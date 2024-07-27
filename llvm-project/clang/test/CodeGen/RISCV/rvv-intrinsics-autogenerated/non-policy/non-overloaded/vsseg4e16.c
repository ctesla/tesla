// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16mf4x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv1f16.i64(<vscale x 1 x half> [[TMP0]], <vscale x 1 x half> [[TMP1]], <vscale x 1 x half> [[TMP2]], <vscale x 1 x half> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16mf4x4(_Float16 *base, vfloat16mf4x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16mf4x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv2f16.i64(<vscale x 2 x half> [[TMP0]], <vscale x 2 x half> [[TMP1]], <vscale x 2 x half> [[TMP2]], <vscale x 2 x half> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16mf2x4(_Float16 *base, vfloat16mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16mf2x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv4f16.i64(<vscale x 4 x half> [[TMP0]], <vscale x 4 x half> [[TMP1]], <vscale x 4 x half> [[TMP2]], <vscale x 4 x half> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16m1x4(_Float16 *base, vfloat16m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16m1x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv8f16.i64(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], <vscale x 8 x half> [[TMP2]], <vscale x 8 x half> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16m2x4(_Float16 *base, vfloat16m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16m2x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16mf4x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], <vscale x 1 x i16> [[TMP2]], <vscale x 1 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16mf4x4(int16_t *base, vint16mf4x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16mf4x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], <vscale x 2 x i16> [[TMP2]], <vscale x 2 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16mf2x4(int16_t *base, vint16mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16mf2x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], <vscale x 4 x i16> [[TMP2]], <vscale x 4 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16m1x4(int16_t *base, vint16m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16m1x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i16> [[TMP2]], <vscale x 8 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16m2x4(int16_t *base, vint16m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16m2x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16mf4x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], <vscale x 1 x i16> [[TMP2]], <vscale x 1 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16mf4x4(uint16_t *base, vuint16mf4x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16mf4x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], <vscale x 2 x i16> [[TMP2]], <vscale x 2 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16mf2x4(uint16_t *base, vuint16mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16mf2x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], <vscale x 4 x i16> [[TMP2]], <vscale x 4 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16m1x4(uint16_t *base, vuint16m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16m1x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i16> [[TMP2]], <vscale x 8 x i16> [[TMP3]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16m2x4(uint16_t *base, vuint16m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16m2x4(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16mf4x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv1f16.i64(<vscale x 1 x half> [[TMP0]], <vscale x 1 x half> [[TMP1]], <vscale x 1 x half> [[TMP2]], <vscale x 1 x half> [[TMP3]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16mf4x4_m(vbool64_t mask, _Float16 *base, vfloat16mf4x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16mf4x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16mf2x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv2f16.i64(<vscale x 2 x half> [[TMP0]], <vscale x 2 x half> [[TMP1]], <vscale x 2 x half> [[TMP2]], <vscale x 2 x half> [[TMP3]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16mf2x4_m(vbool32_t mask, _Float16 *base, vfloat16mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16mf2x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16m1x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv4f16.i64(<vscale x 4 x half> [[TMP0]], <vscale x 4 x half> [[TMP1]], <vscale x 4 x half> [[TMP2]], <vscale x 4 x half> [[TMP3]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16m1x4_m(vbool16_t mask, _Float16 *base, vfloat16m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16m1x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_f16m2x4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv8f16.i64(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], <vscale x 8 x half> [[TMP2]], <vscale x 8 x half> [[TMP3]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_f16m2x4_m(vbool8_t mask, _Float16 *base, vfloat16m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_f16m2x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16mf4x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], <vscale x 1 x i16> [[TMP2]], <vscale x 1 x i16> [[TMP3]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16mf4x4_m(vbool64_t mask, int16_t *base, vint16mf4x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16mf4x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16mf2x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], <vscale x 2 x i16> [[TMP2]], <vscale x 2 x i16> [[TMP3]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16mf2x4_m(vbool32_t mask, int16_t *base, vint16mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16mf2x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16m1x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], <vscale x 4 x i16> [[TMP2]], <vscale x 4 x i16> [[TMP3]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16m1x4_m(vbool16_t mask, int16_t *base, vint16m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16m1x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_i16m2x4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i16> [[TMP2]], <vscale x 8 x i16> [[TMP3]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_i16m2x4_m(vbool8_t mask, int16_t *base, vint16m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_i16m2x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16mf4x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], <vscale x 1 x i16> [[TMP2]], <vscale x 1 x i16> [[TMP3]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16mf4x4_m(vbool64_t mask, uint16_t *base, vuint16mf4x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16mf4x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16mf2x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], <vscale x 2 x i16> [[TMP2]], <vscale x 2 x i16> [[TMP3]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16mf2x4_m(vbool32_t mask, uint16_t *base, vuint16mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16mf2x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16m1x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], <vscale x 4 x i16> [[TMP2]], <vscale x 4 x i16> [[TMP3]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16m1x4_m(vbool16_t mask, uint16_t *base, vuint16m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16m1x4_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e16_v_u16m2x4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i16> [[TMP2]], <vscale x 8 x i16> [[TMP3]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e16_v_u16m2x4_m(vbool8_t mask, uint16_t *base, vuint16m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e16_v_u16m2x4_m(mask, base, v_tuple, vl);
}

