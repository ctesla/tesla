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

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vsha2cl_vv_u32mf2
// CHECK-RV64-SAME: (<vscale x 1 x i32> [[VD:%.*]], <vscale x 1 x i32> [[VS2:%.*]], <vscale x 1 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vsha2cl.nxv1i32.nxv1i32.i64(<vscale x 1 x i32> [[VD]], <vscale x 1 x i32> [[VS2]], <vscale x 1 x i32> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vsha2cl_vv_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, vuint32mf2_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u32mf2(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vsha2cl_vv_u32m1
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[VD:%.*]], <vscale x 2 x i32> [[VS2:%.*]], <vscale x 2 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vsha2cl.nxv2i32.nxv2i32.i64(<vscale x 2 x i32> [[VD]], <vscale x 2 x i32> [[VS2]], <vscale x 2 x i32> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vsha2cl_vv_u32m1(vuint32m1_t vd, vuint32m1_t vs2, vuint32m1_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u32m1(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vsha2cl_vv_u32m2
// CHECK-RV64-SAME: (<vscale x 4 x i32> [[VD:%.*]], <vscale x 4 x i32> [[VS2:%.*]], <vscale x 4 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vsha2cl.nxv4i32.nxv4i32.i64(<vscale x 4 x i32> [[VD]], <vscale x 4 x i32> [[VS2]], <vscale x 4 x i32> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vsha2cl_vv_u32m2(vuint32m2_t vd, vuint32m2_t vs2, vuint32m2_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u32m2(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vsha2cl_vv_u32m4
// CHECK-RV64-SAME: (<vscale x 8 x i32> [[VD:%.*]], <vscale x 8 x i32> [[VS2:%.*]], <vscale x 8 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vsha2cl.nxv8i32.nxv8i32.i64(<vscale x 8 x i32> [[VD]], <vscale x 8 x i32> [[VS2]], <vscale x 8 x i32> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vsha2cl_vv_u32m4(vuint32m4_t vd, vuint32m4_t vs2, vuint32m4_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u32m4(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vsha2cl_vv_u32m8
// CHECK-RV64-SAME: (<vscale x 16 x i32> [[VD:%.*]], <vscale x 16 x i32> [[VS2:%.*]], <vscale x 16 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vsha2cl.nxv16i32.nxv16i32.i64(<vscale x 16 x i32> [[VD]], <vscale x 16 x i32> [[VS2]], <vscale x 16 x i32> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vsha2cl_vv_u32m8(vuint32m8_t vd, vuint32m8_t vs2, vuint32m8_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u32m8(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vsha2cl_vv_u64m1
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[VD:%.*]], <vscale x 1 x i64> [[VS2:%.*]], <vscale x 1 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsha2cl.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> [[VD]], <vscale x 1 x i64> [[VS2]], <vscale x 1 x i64> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vsha2cl_vv_u64m1(vuint64m1_t vd, vuint64m1_t vs2, vuint64m1_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u64m1(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vsha2cl_vv_u64m2
// CHECK-RV64-SAME: (<vscale x 2 x i64> [[VD:%.*]], <vscale x 2 x i64> [[VS2:%.*]], <vscale x 2 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsha2cl.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> [[VD]], <vscale x 2 x i64> [[VS2]], <vscale x 2 x i64> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vsha2cl_vv_u64m2(vuint64m2_t vd, vuint64m2_t vs2, vuint64m2_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u64m2(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vsha2cl_vv_u64m4
// CHECK-RV64-SAME: (<vscale x 4 x i64> [[VD:%.*]], <vscale x 4 x i64> [[VS2:%.*]], <vscale x 4 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsha2cl.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> [[VD]], <vscale x 4 x i64> [[VS2]], <vscale x 4 x i64> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vsha2cl_vv_u64m4(vuint64m4_t vd, vuint64m4_t vs2, vuint64m4_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u64m4(vd, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vsha2cl_vv_u64m8
// CHECK-RV64-SAME: (<vscale x 8 x i64> [[VD:%.*]], <vscale x 8 x i64> [[VS2:%.*]], <vscale x 8 x i64> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsha2cl.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> [[VD]], <vscale x 8 x i64> [[VS2]], <vscale x 8 x i64> [[VS1]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vsha2cl_vv_u64m8(vuint64m8_t vd, vuint64m8_t vs2, vuint64m8_t vs1, size_t vl) {
  return __riscv_vsha2cl_vv_u64m8(vd, vs2, vs1, vl);
}

