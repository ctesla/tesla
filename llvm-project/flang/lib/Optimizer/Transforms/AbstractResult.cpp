//===- AbstractResult.cpp - Conversion of Abstract Function Result --------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "flang/Optimizer/Builder/FIRBuilder.h"
#include "flang/Optimizer/Builder/Todo.h"
#include "flang/Optimizer/Dialect/FIRDialect.h"
#include "flang/Optimizer/Dialect/FIROps.h"
#include "flang/Optimizer/Dialect/FIRType.h"
#include "flang/Optimizer/Dialect/Support/FIRContext.h"
#include "flang/Optimizer/Transforms/Passes.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Diagnostics.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Transforms/DialectConversion.h"
#include "llvm/ADT/TypeSwitch.h"

namespace fir {
#define GEN_PASS_DEF_ABSTRACTRESULTOPT
#include "flang/Optimizer/Transforms/Passes.h.inc"
} // namespace fir

#define DEBUG_TYPE "flang-abstract-result-opt"

using namespace mlir;

namespace fir {
namespace {

static mlir::Type getResultArgumentType(mlir::Type resultType,
                                        bool shouldBoxResult) {
  return llvm::TypeSwitch<mlir::Type, mlir::Type>(resultType)
      .Case<fir::SequenceType, fir::RecordType>(
          [&](mlir::Type type) -> mlir::Type {
            if (shouldBoxResult)
              return fir::BoxType::get(type);
            return fir::ReferenceType::get(type);
          })
      .Case<fir::BaseBoxType>([](mlir::Type type) -> mlir::Type {
        return fir::ReferenceType::get(type);
      })
      .Default([](mlir::Type) -> mlir::Type {
        llvm_unreachable("bad abstract result type");
      });
}

static mlir::FunctionType getNewFunctionType(mlir::FunctionType funcTy,
                                             bool shouldBoxResult) {
  auto resultType = funcTy.getResult(0);
  auto argTy = getResultArgumentType(resultType, shouldBoxResult);
  llvm::SmallVector<mlir::Type> newInputTypes = {argTy};
  newInputTypes.append(funcTy.getInputs().begin(), funcTy.getInputs().end());
  return mlir::FunctionType::get(funcTy.getContext(), newInputTypes,
                                 /*resultTypes=*/{});
}

static mlir::Type getVoidPtrType(mlir::MLIRContext *context) {
  return fir::ReferenceType::get(mlir::NoneType::get(context));
}

/// This is for function result types that are of type C_PTR from ISO_C_BINDING.
/// Follow the ABI for interoperability with C.
static mlir::FunctionType getCPtrFunctionType(mlir::FunctionType funcTy) {
  assert(fir::isa_builtin_cptr_type(funcTy.getResult(0)));
  llvm::SmallVector<mlir::Type> outputTypes{
      getVoidPtrType(funcTy.getContext())};
  return mlir::FunctionType::get(funcTy.getContext(), funcTy.getInputs(),
                                 outputTypes);
}

static bool mustEmboxResult(mlir::Type resultType, bool shouldBoxResult) {
  return mlir::isa<fir::SequenceType, fir::RecordType>(resultType) &&
         shouldBoxResult;
}

template <typename Op>
class CallConversion : public mlir::OpRewritePattern<Op> {
public:
  using mlir::OpRewritePattern<Op>::OpRewritePattern;

  CallConversion(mlir::MLIRContext *context, bool shouldBoxResult)
      : OpRewritePattern<Op>(context, 1), shouldBoxResult{shouldBoxResult} {}

  llvm::LogicalResult
  matchAndRewrite(Op op, mlir::PatternRewriter &rewriter) const override {
    auto loc = op.getLoc();
    auto result = op->getResult(0);
    if (!result.hasOneUse()) {
      mlir::emitError(loc,
                      "calls with abstract result must have exactly one user");
      return mlir::failure();
    }
    auto saveResult =
        mlir::dyn_cast<fir::SaveResultOp>(result.use_begin().getUser());
    if (!saveResult) {
      mlir::emitError(
          loc, "calls with abstract result must be used in fir.save_result");
      return mlir::failure();
    }
    auto argType = getResultArgumentType(result.getType(), shouldBoxResult);
    auto buffer = saveResult.getMemref();
    mlir::Value arg = buffer;
    if (mustEmboxResult(result.getType(), shouldBoxResult))
      arg = rewriter.create<fir::EmboxOp>(
          loc, argType, buffer, saveResult.getShape(), /*slice*/ mlir::Value{},
          saveResult.getTypeparams());

    llvm::SmallVector<mlir::Type> newResultTypes;
    bool isResultBuiltinCPtr = fir::isa_builtin_cptr_type(result.getType());
    if (isResultBuiltinCPtr)
      newResultTypes.emplace_back(getVoidPtrType(result.getContext()));

    Op newOp;
    // fir::CallOp specific handling.
    if constexpr (std::is_same_v<Op, fir::CallOp>) {
      if (op.getCallee()) {
        llvm::SmallVector<mlir::Value> newOperands;
        if (!isResultBuiltinCPtr)
          newOperands.emplace_back(arg);
        newOperands.append(op.getOperands().begin(), op.getOperands().end());
        newOp = rewriter.create<fir::CallOp>(loc, *op.getCallee(),
                                             newResultTypes, newOperands);
      } else {
        // Indirect calls.
        llvm::SmallVector<mlir::Type> newInputTypes;
        if (!isResultBuiltinCPtr)
          newInputTypes.emplace_back(argType);
        for (auto operand : op.getOperands().drop_front())
          newInputTypes.push_back(operand.getType());
        auto newFuncTy = mlir::FunctionType::get(op.getContext(), newInputTypes,
                                                 newResultTypes);

        llvm::SmallVector<mlir::Value> newOperands;
        newOperands.push_back(
            rewriter.create<fir::ConvertOp>(loc, newFuncTy, op.getOperand(0)));
        if (!isResultBuiltinCPtr)
          newOperands.push_back(arg);
        newOperands.append(op.getOperands().begin() + 1,
                           op.getOperands().end());
        newOp = rewriter.create<fir::CallOp>(loc, mlir::SymbolRefAttr{},
                                             newResultTypes, newOperands);
      }
    }

    // fir::DispatchOp specific handling.
    if constexpr (std::is_same_v<Op, fir::DispatchOp>) {
      llvm::SmallVector<mlir::Value> newOperands;
      if (!isResultBuiltinCPtr)
        newOperands.emplace_back(arg);
      unsigned passArgShift = newOperands.size();
      newOperands.append(op.getOperands().begin() + 1, op.getOperands().end());

      fir::DispatchOp newDispatchOp;
      if (op.getPassArgPos())
        newOp = rewriter.create<fir::DispatchOp>(
            loc, newResultTypes, rewriter.getStringAttr(op.getMethod()),
            op.getOperands()[0], newOperands,
            rewriter.getI32IntegerAttr(*op.getPassArgPos() + passArgShift));
      else
        newOp = rewriter.create<fir::DispatchOp>(
            loc, newResultTypes, rewriter.getStringAttr(op.getMethod()),
            op.getOperands()[0], newOperands, nullptr);
    }

    if (isResultBuiltinCPtr) {
      mlir::Value save = saveResult.getMemref();
      auto module = op->template getParentOfType<mlir::ModuleOp>();
      FirOpBuilder builder(rewriter, module);
      mlir::Value saveAddr = fir::factory::genCPtrOrCFunptrAddr(
          builder, loc, save, result.getType());
      builder.createStoreWithConvert(loc, newOp->getResult(0), saveAddr);
    }
    op->dropAllReferences();
    rewriter.eraseOp(op);
    return mlir::success();
  }

private:
  bool shouldBoxResult;
};

class SaveResultOpConversion
    : public mlir::OpRewritePattern<fir::SaveResultOp> {
public:
  using OpRewritePattern::OpRewritePattern;
  SaveResultOpConversion(mlir::MLIRContext *context)
      : OpRewritePattern(context) {}
  llvm::LogicalResult
  matchAndRewrite(fir::SaveResultOp op,
                  mlir::PatternRewriter &rewriter) const override {
    rewriter.eraseOp(op);
    return mlir::success();
  }
};

class ReturnOpConversion : public mlir::OpRewritePattern<mlir::func::ReturnOp> {
public:
  using OpRewritePattern::OpRewritePattern;
  ReturnOpConversion(mlir::MLIRContext *context, mlir::Value newArg)
      : OpRewritePattern(context), newArg{newArg} {}
  llvm::LogicalResult
  matchAndRewrite(mlir::func::ReturnOp ret,
                  mlir::PatternRewriter &rewriter) const override {
    auto loc = ret.getLoc();
    rewriter.setInsertionPoint(ret);
    mlir::Value resultValue = ret.getOperand(0);
    fir::LoadOp resultLoad;
    mlir::Value resultStorage;
    // Identify result local storage.
    if (auto load = resultValue.getDefiningOp<fir::LoadOp>()) {
      resultLoad = load;
      resultStorage = load.getMemref();
      // The result alloca may be behind a fir.declare, if any.
      if (auto declare = resultStorage.getDefiningOp<fir::DeclareOp>())
        resultStorage = declare.getMemref();
    }
    // Replace old local storage with new storage argument, unless
    // the derived type is C_PTR/C_FUN_PTR, in which case the return
    // type is updated to return void* (no new argument is passed).
    if (fir::isa_builtin_cptr_type(resultValue.getType())) {
      auto module = ret->getParentOfType<mlir::ModuleOp>();
      FirOpBuilder builder(rewriter, module);
      mlir::Value cptr = resultValue;
      if (resultLoad) {
        // Replace whole derived type load by component load.
        cptr = resultLoad.getMemref();
        rewriter.setInsertionPoint(resultLoad);
      }
      mlir::Value newResultValue =
          fir::factory::genCPtrOrCFunptrValue(builder, loc, cptr);
      newResultValue = builder.createConvert(
          loc, getVoidPtrType(ret.getContext()), newResultValue);
      rewriter.setInsertionPoint(ret);
      rewriter.replaceOpWithNewOp<mlir::func::ReturnOp>(
          ret, mlir::ValueRange{newResultValue});
    } else if (resultStorage) {
      resultStorage.replaceAllUsesWith(newArg);
      rewriter.replaceOpWithNewOp<mlir::func::ReturnOp>(ret);
    } else {
      // The result storage may have been optimized out by a memory to
      // register pass, this is possible for fir.box results, or fir.record
      // with no length parameters. Simply store the result in the result
      // storage. at the return point.
      rewriter.create<fir::StoreOp>(loc, resultValue, newArg);
      rewriter.replaceOpWithNewOp<mlir::func::ReturnOp>(ret);
    }
    // Delete result old local storage if unused.
    if (resultStorage)
      if (auto alloc = resultStorage.getDefiningOp<fir::AllocaOp>())
        if (alloc->use_empty())
          rewriter.eraseOp(alloc);
    return mlir::success();
  }

private:
  mlir::Value newArg;
};

class AddrOfOpConversion : public mlir::OpRewritePattern<fir::AddrOfOp> {
public:
  using OpRewritePattern::OpRewritePattern;
  AddrOfOpConversion(mlir::MLIRContext *context, bool shouldBoxResult)
      : OpRewritePattern(context), shouldBoxResult{shouldBoxResult} {}
  llvm::LogicalResult
  matchAndRewrite(fir::AddrOfOp addrOf,
                  mlir::PatternRewriter &rewriter) const override {
    auto oldFuncTy = mlir::cast<mlir::FunctionType>(addrOf.getType());
    mlir::FunctionType newFuncTy;
    if (oldFuncTy.getNumResults() != 0 &&
        fir::isa_builtin_cptr_type(oldFuncTy.getResult(0)))
      newFuncTy = getCPtrFunctionType(oldFuncTy);
    else
      newFuncTy = getNewFunctionType(oldFuncTy, shouldBoxResult);
    auto newAddrOf = rewriter.create<fir::AddrOfOp>(addrOf.getLoc(), newFuncTy,
                                                    addrOf.getSymbol());
    // Rather than converting all op a function pointer might transit through
    // (e.g calls, stores, loads, converts...), cast new type to the abstract
    // type. A conversion will be added when calling indirect calls of abstract
    // types.
    rewriter.replaceOpWithNewOp<fir::ConvertOp>(addrOf, oldFuncTy, newAddrOf);
    return mlir::success();
  }

private:
  bool shouldBoxResult;
};

class AbstractResultOpt
    : public fir::impl::AbstractResultOptBase<AbstractResultOpt> {
public:
  using fir::impl::AbstractResultOptBase<
      AbstractResultOpt>::AbstractResultOptBase;

  void runOnSpecificOperation(mlir::func::FuncOp func, bool shouldBoxResult,
                              mlir::RewritePatternSet &patterns,
                              mlir::ConversionTarget &target) {
    auto loc = func.getLoc();
    auto *context = &getContext();
    // Convert function type itself if it has an abstract result.
    auto funcTy = mlir::cast<mlir::FunctionType>(func.getFunctionType());
    if (hasAbstractResult(funcTy)) {
      if (fir::isa_builtin_cptr_type(funcTy.getResult(0))) {
        func.setType(getCPtrFunctionType(funcTy));
        patterns.insert<ReturnOpConversion>(context, mlir::Value{});
        target.addDynamicallyLegalOp<mlir::func::ReturnOp>(
            [](mlir::func::ReturnOp ret) {
              mlir::Type retTy = ret.getOperand(0).getType();
              return !fir::isa_builtin_cptr_type(retTy);
            });
        return;
      }
      if (!func.empty()) {
        // Insert new argument.
        mlir::OpBuilder rewriter(context);
        auto resultType = funcTy.getResult(0);
        auto argTy = getResultArgumentType(resultType, shouldBoxResult);
        func.insertArgument(0u, argTy, {}, loc);
        func.eraseResult(0u);
        mlir::Value newArg = func.getArgument(0u);
        if (mustEmboxResult(resultType, shouldBoxResult)) {
          auto bufferType = fir::ReferenceType::get(resultType);
          rewriter.setInsertionPointToStart(&func.front());
          newArg = rewriter.create<fir::BoxAddrOp>(loc, bufferType, newArg);
        }
        patterns.insert<ReturnOpConversion>(context, newArg);
        target.addDynamicallyLegalOp<mlir::func::ReturnOp>(
            [](mlir::func::ReturnOp ret) { return ret.getOperands().empty(); });
        assert(func.getFunctionType() ==
               getNewFunctionType(funcTy, shouldBoxResult));
      } else {
        llvm::SmallVector<mlir::DictionaryAttr> allArgs;
        func.getAllArgAttrs(allArgs);
        allArgs.insert(allArgs.begin(),
                       mlir::DictionaryAttr::get(func->getContext()));
        func.setType(getNewFunctionType(funcTy, shouldBoxResult));
        func.setAllArgAttrs(allArgs);
      }
    }
  }

  inline static bool containsFunctionTypeWithAbstractResult(mlir::Type type) {
    return mlir::TypeSwitch<mlir::Type, bool>(type)
        .Case([](fir::BoxProcType boxProc) {
          return fir::hasAbstractResult(
              mlir::cast<mlir::FunctionType>(boxProc.getEleTy()));
        })
        .Case([](fir::PointerType pointer) {
          return fir::hasAbstractResult(
              mlir::cast<mlir::FunctionType>(pointer.getEleTy()));
        })
        .Default([](auto &&) { return false; });
  }

  void runOnSpecificOperation(fir::GlobalOp global, bool,
                              mlir::RewritePatternSet &,
                              mlir::ConversionTarget &) {
    if (containsFunctionTypeWithAbstractResult(global.getType())) {
      TODO(global->getLoc(), "support for procedure pointers");
    }
  }

  /// Run the pass on a ModuleOp. This makes fir-opt --abstract-result work.
  void runOnModule() {
    mlir::ModuleOp mod = mlir::cast<mlir::ModuleOp>(getOperation());

    auto pass = std::make_unique<AbstractResultOpt>();
    pass->copyOptionValuesFrom(this);
    mlir::OpPassManager pipeline;
    pipeline.addPass(std::unique_ptr<mlir::Pass>{pass.release()});

    // Run the pass on all operations directly nested inside of the ModuleOp
    // we can't just call runOnSpecificOperation here because the pass
    // implementation only works when scoped to a particular func.func or
    // fir.global
    for (mlir::Region &region : mod->getRegions()) {
      for (mlir::Block &block : region.getBlocks()) {
        for (mlir::Operation &op : block.getOperations()) {
          if (mlir::failed(runPipeline(pipeline, &op))) {
            mlir::emitError(op.getLoc(), "Failed to run abstract result pass");
            signalPassFailure();
            return;
          }
        }
      }
    }
  }

  void runOnOperation() override {
    auto *context = &this->getContext();
    mlir::Operation *op = this->getOperation();
    if (mlir::isa<mlir::ModuleOp>(op)) {
      runOnModule();
      return;
    }

    mlir::RewritePatternSet patterns(context);
    mlir::ConversionTarget target = *context;
    const bool shouldBoxResult = this->passResultAsBox.getValue();

    mlir::TypeSwitch<mlir::Operation *, void>(op)
        .Case<mlir::func::FuncOp, fir::GlobalOp>([&](auto op) {
          runOnSpecificOperation(op, shouldBoxResult, patterns, target);
        });

    // Convert the calls and, if needed,  the ReturnOp in the function body.
    target.addLegalDialect<fir::FIROpsDialect, mlir::arith::ArithDialect,
                           mlir::func::FuncDialect>();
    target.addIllegalOp<fir::SaveResultOp>();
    target.addDynamicallyLegalOp<fir::CallOp>([](fir::CallOp call) {
      return !hasAbstractResult(call.getFunctionType());
    });
    target.addDynamicallyLegalOp<fir::AddrOfOp>([](fir::AddrOfOp addrOf) {
      if (auto funTy = mlir::dyn_cast<mlir::FunctionType>(addrOf.getType()))
        return !hasAbstractResult(funTy);
      return true;
    });
    target.addDynamicallyLegalOp<fir::DispatchOp>([](fir::DispatchOp dispatch) {
      return !hasAbstractResult(dispatch.getFunctionType());
    });

    patterns.insert<CallConversion<fir::CallOp>>(context, shouldBoxResult);
    patterns.insert<CallConversion<fir::DispatchOp>>(context, shouldBoxResult);
    patterns.insert<SaveResultOpConversion>(context);
    patterns.insert<AddrOfOpConversion>(context, shouldBoxResult);
    if (mlir::failed(
            mlir::applyPartialConversion(op, target, std::move(patterns)))) {
      mlir::emitError(op->getLoc(), "error in converting abstract results\n");
      this->signalPassFailure();
    }
  }
};

} // end anonymous namespace
} // namespace fir
