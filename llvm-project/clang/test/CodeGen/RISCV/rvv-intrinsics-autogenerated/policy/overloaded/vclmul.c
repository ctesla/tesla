// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zvl512b \
// RUN:   -target-feature +zvbb \
// RUN:   -target-feature +zvbc \
// RUN:   -target-feature +zvkb \
// RUN:   -target-feature +zvkg \
// RUN:   -target-feature +zvkned \
// RUN:   -target-feature +zvknhb \
// RUN:   -target-feature +zvksed \
// RUN:   -target-feature +zvksh \
// RUN:   -target-feature +experimental \
// RUN:   -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vv_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], <vscale x 1 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], <vscale x 1 x i64> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vv_u64m1_tu(vuint64m1_t maskedoff, vuint64m1_t vs2, vuint64m1_t vs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vx_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.nxv1i64.i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vx_u64m1_tu(vuint64m1_t maskedoff, vuint64m1_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vv_u64m2_tu
// CHECK-RV64-SAME: (<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], <vscale x 2 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], <vscale x 2 x i64> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vv_u64m2_tu(vuint64m2_t maskedoff, vuint64m2_t vs2, vuint64m2_t vs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vx_u64m2_tu
// CHECK-RV64-SAME: (<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.nxv2i64.i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vx_u64m2_tu(vuint64m2_t maskedoff, vuint64m2_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vv_u64m4_tu
// CHECK-RV64-SAME: (<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], <vscale x 4 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], <vscale x 4 x i64> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vv_u64m4_tu(vuint64m4_t maskedoff, vuint64m4_t vs2, vuint64m4_t vs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vx_u64m4_tu
// CHECK-RV64-SAME: (<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.nxv4i64.i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vx_u64m4_tu(vuint64m4_t maskedoff, vuint64m4_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vv_u64m8_tu
// CHECK-RV64-SAME: (<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], <vscale x 8 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], <vscale x 8 x i64> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vv_u64m8_tu(vuint64m8_t maskedoff, vuint64m8_t vs2, vuint64m8_t vs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vx_u64m8_tu
// CHECK-RV64-SAME: (<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.nxv8i64.i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vx_u64m8_tu(vuint64m8_t maskedoff, vuint64m8_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tu(maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vv_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], <vscale x 1 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.mask.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], <vscale x 1 x i64> [[VS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vv_u64m1_tum(vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t vs2, vuint64m1_t vs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vx_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.mask.nxv1i64.i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], i64 [[RS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vx_u64m1_tum(vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vv_u64m2_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], <vscale x 2 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.mask.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], <vscale x 2 x i64> [[VS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vv_u64m2_tum(vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t vs2, vuint64m2_t vs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vx_u64m2_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.mask.nxv2i64.i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], i64 [[RS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vx_u64m2_tum(vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vv_u64m4_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], <vscale x 4 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.mask.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], <vscale x 4 x i64> [[VS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vv_u64m4_tum(vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t vs2, vuint64m4_t vs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vx_u64m4_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.mask.nxv4i64.i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], i64 [[RS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vx_u64m4_tum(vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vv_u64m8_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], <vscale x 8 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.mask.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], <vscale x 8 x i64> [[VS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vv_u64m8_tum(vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t vs2, vuint64m8_t vs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vx_u64m8_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.mask.nxv8i64.i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], i64 [[RS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vx_u64m8_tum(vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tum(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vv_u64m1_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], <vscale x 1 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.mask.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], <vscale x 1 x i64> [[VS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vv_u64m1_tumu(vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t vs2, vuint64m1_t vs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vx_u64m1_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.mask.nxv1i64.i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], i64 [[RS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vx_u64m1_tumu(vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vv_u64m2_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], <vscale x 2 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.mask.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], <vscale x 2 x i64> [[VS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vv_u64m2_tumu(vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t vs2, vuint64m2_t vs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vx_u64m2_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.mask.nxv2i64.i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], i64 [[RS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vx_u64m2_tumu(vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vv_u64m4_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], <vscale x 4 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.mask.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], <vscale x 4 x i64> [[VS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vv_u64m4_tumu(vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t vs2, vuint64m4_t vs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vx_u64m4_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.mask.nxv4i64.i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], i64 [[RS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vx_u64m4_tumu(vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vv_u64m8_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], <vscale x 8 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.mask.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], <vscale x 8 x i64> [[VS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vv_u64m8_tumu(vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t vs2, vuint64m8_t vs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vx_u64m8_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.mask.nxv8i64.i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], i64 [[RS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vx_u64m8_tumu(vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_tumu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vv_u64m1_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], <vscale x 1 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.mask.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], <vscale x 1 x i64> [[VS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vv_u64m1_mu(vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t vs2, vuint64m1_t vs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vclmul_vx_u64m1_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vclmul.mask.nxv1i64.i64.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i64> [[VS2]], i64 [[RS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vclmul_vx_u64m1_mu(vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vv_u64m2_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], <vscale x 2 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.mask.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], <vscale x 2 x i64> [[VS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vv_u64m2_mu(vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t vs2, vuint64m2_t vs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vclmul_vx_u64m2_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vclmul.mask.nxv2i64.i64.i64(<vscale x 2 x i64> [[MASKEDOFF]], <vscale x 2 x i64> [[VS2]], i64 [[RS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vclmul_vx_u64m2_mu(vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vv_u64m4_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], <vscale x 4 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.mask.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], <vscale x 4 x i64> [[VS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vv_u64m4_mu(vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t vs2, vuint64m4_t vs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vclmul_vx_u64m4_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vclmul.mask.nxv4i64.i64.i64(<vscale x 4 x i64> [[MASKEDOFF]], <vscale x 4 x i64> [[VS2]], i64 [[RS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vclmul_vx_u64m4_mu(vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vv_u64m8_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], <vscale x 8 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.mask.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], <vscale x 8 x i64> [[VS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vv_u64m8_mu(vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t vs2, vuint64m8_t vs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vclmul_vx_u64m8_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vclmul.mask.nxv8i64.i64.i64(<vscale x 8 x i64> [[MASKEDOFF]], <vscale x 8 x i64> [[VS2]], i64 [[RS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vclmul_vx_u64m8_mu(vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t vs2, uint64_t rs1, size_t vl) {
  return __riscv_vclmul_mu(mask, maskedoff, vs2, rs1, vl);
}

