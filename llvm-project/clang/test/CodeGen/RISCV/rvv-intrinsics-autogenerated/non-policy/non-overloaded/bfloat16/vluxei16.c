// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vluxei16_v_bf16mf4(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x bfloat> @llvm.riscv.vluxei.nxv1bf16.nxv1i16.i64(<vscale x 1 x bfloat> poison, ptr [[RS1]], <vscale x 1 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP0]]
//
vbfloat16mf4_t test_vluxei16_v_bf16mf4(const __bf16 *rs1, vuint16mf4_t rs2,
                                       size_t vl) {
  return __riscv_vluxei16_v_bf16mf4(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vluxei16_v_bf16mf2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.riscv.vluxei.nxv2bf16.nxv2i16.i64(<vscale x 2 x bfloat> poison, ptr [[RS1]], <vscale x 2 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vluxei16_v_bf16mf2(const __bf16 *rs1, vuint16mf2_t rs2,
                                       size_t vl) {
  return __riscv_vluxei16_v_bf16mf2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vluxei16_v_bf16m1(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.riscv.vluxei.nxv4bf16.nxv4i16.i64(<vscale x 4 x bfloat> poison, ptr [[RS1]], <vscale x 4 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vluxei16_v_bf16m1(const __bf16 *rs1, vuint16m1_t rs2,
                                     size_t vl) {
  return __riscv_vluxei16_v_bf16m1(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vluxei16_v_bf16m2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 8 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.riscv.vluxei.nxv8bf16.nxv8i16.i64(<vscale x 8 x bfloat> poison, ptr [[RS1]], <vscale x 8 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vluxei16_v_bf16m2(const __bf16 *rs1, vuint16m2_t rs2,
                                     size_t vl) {
  return __riscv_vluxei16_v_bf16m2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vluxei16_v_bf16m4(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 16 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.riscv.vluxei.nxv16bf16.nxv16i16.i64(<vscale x 16 x bfloat> poison, ptr [[RS1]], <vscale x 16 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vluxei16_v_bf16m4(const __bf16 *rs1, vuint16m4_t rs2,
                                     size_t vl) {
  return __riscv_vluxei16_v_bf16m4(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vluxei16_v_bf16m8(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 32 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.riscv.vluxei.nxv32bf16.nxv32i16.i64(<vscale x 32 x bfloat> poison, ptr [[RS1]], <vscale x 32 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vluxei16_v_bf16m8(const __bf16 *rs1, vuint16m8_t rs2,
                                     size_t vl) {
  return __riscv_vluxei16_v_bf16m8(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vluxei16_v_bf16mf4_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x bfloat> @llvm.riscv.vluxei.mask.nxv1bf16.nxv1i16.i64(<vscale x 1 x bfloat> poison, ptr [[RS1]], <vscale x 1 x i16> [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP0]]
//
vbfloat16mf4_t test_vluxei16_v_bf16mf4_m(vbool64_t vm, const __bf16 *rs1,
                                         vuint16mf4_t rs2, size_t vl) {
  return __riscv_vluxei16_v_bf16mf4_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vluxei16_v_bf16mf2_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.riscv.vluxei.mask.nxv2bf16.nxv2i16.i64(<vscale x 2 x bfloat> poison, ptr [[RS1]], <vscale x 2 x i16> [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vluxei16_v_bf16mf2_m(vbool32_t vm, const __bf16 *rs1,
                                         vuint16mf2_t rs2, size_t vl) {
  return __riscv_vluxei16_v_bf16mf2_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vluxei16_v_bf16m1_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.riscv.vluxei.mask.nxv4bf16.nxv4i16.i64(<vscale x 4 x bfloat> poison, ptr [[RS1]], <vscale x 4 x i16> [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vluxei16_v_bf16m1_m(vbool16_t vm, const __bf16 *rs1,
                                       vuint16m1_t rs2, size_t vl) {
  return __riscv_vluxei16_v_bf16m1_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vluxei16_v_bf16m2_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 8 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.riscv.vluxei.mask.nxv8bf16.nxv8i16.i64(<vscale x 8 x bfloat> poison, ptr [[RS1]], <vscale x 8 x i16> [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vluxei16_v_bf16m2_m(vbool8_t vm, const __bf16 *rs1,
                                       vuint16m2_t rs2, size_t vl) {
  return __riscv_vluxei16_v_bf16m2_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vluxei16_v_bf16m4_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 16 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.riscv.vluxei.mask.nxv16bf16.nxv16i16.i64(<vscale x 16 x bfloat> poison, ptr [[RS1]], <vscale x 16 x i16> [[RS2]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vluxei16_v_bf16m4_m(vbool4_t vm, const __bf16 *rs1,
                                       vuint16m4_t rs2, size_t vl) {
  return __riscv_vluxei16_v_bf16m4_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vluxei16_v_bf16m8_m(
// CHECK-RV64-SAME: <vscale x 32 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 32 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.riscv.vluxei.mask.nxv32bf16.nxv32i16.i64(<vscale x 32 x bfloat> poison, ptr [[RS1]], <vscale x 32 x i16> [[RS2]], <vscale x 32 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vluxei16_v_bf16m8_m(vbool2_t vm, const __bf16 *rs1,
                                       vuint16m8_t rs2, size_t vl) {
  return __riscv_vluxei16_v_bf16m8_m(vm, rs1, rs2, vl);
}
