//===--- UseInternalLinkageCheck.cpp - clang-tidy--------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "UseInternalLinkageCheck.h"
#include "../utils/FileExtensionsUtils.h"
#include "clang/AST/Decl.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersMacros.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/Specifiers.h"
#include "llvm/ADT/STLExtras.h"

using namespace clang::ast_matchers;

namespace clang::tidy {

template <>
struct OptionEnumMapping<misc::UseInternalLinkageCheck::FixModeKind> {
  static llvm::ArrayRef<
      std::pair<misc::UseInternalLinkageCheck::FixModeKind, StringRef>>
  getEnumMapping() {
    static constexpr std::pair<misc::UseInternalLinkageCheck::FixModeKind,
                               StringRef>
        Mapping[] = {
            {misc::UseInternalLinkageCheck::FixModeKind::None, "None"},
            {misc::UseInternalLinkageCheck::FixModeKind::UseStatic,
             "UseStatic"},
        };
    return {Mapping};
  }
};

} // namespace clang::tidy

namespace clang::tidy::misc {

namespace {

AST_MATCHER(Decl, isFirstDecl) { return Node.isFirstDecl(); }

static bool isInMainFile(SourceLocation L, SourceManager &SM,
                         const FileExtensionsSet &HeaderFileExtensions) {
  for (;;) {
    if (utils::isSpellingLocInHeaderFile(L, SM, HeaderFileExtensions))
      return false;
    if (SM.isInMainFile(L))
      return true;
    // not in header file but not in main file
    L = SM.getIncludeLoc(SM.getFileID(L));
    if (L.isValid())
      continue;
    // Conservative about the unknown
    return false;
  }
}

AST_MATCHER_P(Decl, isAllRedeclsInMainFile, FileExtensionsSet,
              HeaderFileExtensions) {
  return llvm::all_of(Node.redecls(), [&](const Decl *D) {
    return isInMainFile(D->getLocation(),
                        Finder->getASTContext().getSourceManager(),
                        HeaderFileExtensions);
  });
}

AST_POLYMORPHIC_MATCHER(isExternStorageClass,
                        AST_POLYMORPHIC_SUPPORTED_TYPES(FunctionDecl,
                                                        VarDecl)) {
  return Node.getStorageClass() == SC_Extern;
}

} // namespace

UseInternalLinkageCheck::UseInternalLinkageCheck(StringRef Name,
                                                 ClangTidyContext *Context)
    : ClangTidyCheck(Name, Context),
      HeaderFileExtensions(Context->getHeaderFileExtensions()),
      FixMode(Options.get("FixMode", FixModeKind::UseStatic)) {}

void UseInternalLinkageCheck::storeOptions(ClangTidyOptions::OptionMap &Opts) {
  Options.store(Opts, "FixMode", FixMode);
}

void UseInternalLinkageCheck::registerMatchers(MatchFinder *Finder) {
  auto Common =
      allOf(isFirstDecl(), isAllRedeclsInMainFile(HeaderFileExtensions),
            unless(anyOf(
                // 1. internal linkage
                isStaticStorageClass(), isInAnonymousNamespace(),
                // 2. explicit external linkage
                isExternStorageClass(), isExternC(),
                // 3. template
                isExplicitTemplateSpecialization(),
                // 4. friend
                hasAncestor(friendDecl()))));
  Finder->addMatcher(
      functionDecl(Common, unless(cxxMethodDecl()), unless(isMain()))
          .bind("fn"),
      this);
  Finder->addMatcher(varDecl(Common, hasGlobalStorage()).bind("var"), this);
}

static constexpr StringRef Message =
    "%0 %1 can be made static or moved into an anonymous namespace "
    "to enforce internal linkage";

void UseInternalLinkageCheck::check(const MatchFinder::MatchResult &Result) {
  if (const auto *FD = Result.Nodes.getNodeAs<FunctionDecl>("fn")) {
    DiagnosticBuilder DB = diag(FD->getLocation(), Message) << "function" << FD;
    SourceLocation FixLoc = FD->getTypeSpecStartLoc();
    if (FixLoc.isInvalid() || FixLoc.isMacroID())
      return;
    if (FixMode == FixModeKind::UseStatic)
      DB << FixItHint::CreateInsertion(FixLoc, "static ");
    return;
  }
  if (const auto *VD = Result.Nodes.getNodeAs<VarDecl>("var")) {
    // In C++, const variables at file scope have implicit internal linkage,
    // so we should not warn there. This is not the case in C.
    // https://eel.is/c++draft/diff#basic-3
    if (getLangOpts().CPlusPlus && VD->getType().isConstQualified())
      return;

    DiagnosticBuilder DB = diag(VD->getLocation(), Message) << "variable" << VD;
    SourceLocation FixLoc = VD->getTypeSpecStartLoc();
    if (FixLoc.isInvalid() || FixLoc.isMacroID())
      return;
    if (FixMode == FixModeKind::UseStatic)
      DB << FixItHint::CreateInsertion(FixLoc, "static ");
    return;
  }
  llvm_unreachable("");
}

} // namespace clang::tidy::misc
