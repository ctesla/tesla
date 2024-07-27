// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8mf8x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv1i8.i64(<vscale x 1 x i8> [[TMP0]], <vscale x 1 x i8> [[TMP1]], <vscale x 1 x i8> [[TMP2]], <vscale x 1 x i8> [[TMP3]], <vscale x 1 x i8> [[TMP4]], <vscale x 1 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8mf8x6(int8_t *base, ptrdiff_t bstride, vint8mf8x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8mf4x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv2i8.i64(<vscale x 2 x i8> [[TMP0]], <vscale x 2 x i8> [[TMP1]], <vscale x 2 x i8> [[TMP2]], <vscale x 2 x i8> [[TMP3]], <vscale x 2 x i8> [[TMP4]], <vscale x 2 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8mf4x6(int8_t *base, ptrdiff_t bstride, vint8mf4x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv4i8.i64(<vscale x 4 x i8> [[TMP0]], <vscale x 4 x i8> [[TMP1]], <vscale x 4 x i8> [[TMP2]], <vscale x 4 x i8> [[TMP3]], <vscale x 4 x i8> [[TMP4]], <vscale x 4 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8mf2x6(int8_t *base, ptrdiff_t bstride, vint8mf2x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv8i8.i64(<vscale x 8 x i8> [[TMP0]], <vscale x 8 x i8> [[TMP1]], <vscale x 8 x i8> [[TMP2]], <vscale x 8 x i8> [[TMP3]], <vscale x 8 x i8> [[TMP4]], <vscale x 8 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8m1x6(int8_t *base, ptrdiff_t bstride, vint8m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8mf8x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv1i8.i64(<vscale x 1 x i8> [[TMP0]], <vscale x 1 x i8> [[TMP1]], <vscale x 1 x i8> [[TMP2]], <vscale x 1 x i8> [[TMP3]], <vscale x 1 x i8> [[TMP4]], <vscale x 1 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8mf8x6(uint8_t *base, ptrdiff_t bstride, vuint8mf8x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8mf4x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv2i8.i64(<vscale x 2 x i8> [[TMP0]], <vscale x 2 x i8> [[TMP1]], <vscale x 2 x i8> [[TMP2]], <vscale x 2 x i8> [[TMP3]], <vscale x 2 x i8> [[TMP4]], <vscale x 2 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8mf4x6(uint8_t *base, ptrdiff_t bstride, vuint8mf4x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv4i8.i64(<vscale x 4 x i8> [[TMP0]], <vscale x 4 x i8> [[TMP1]], <vscale x 4 x i8> [[TMP2]], <vscale x 4 x i8> [[TMP3]], <vscale x 4 x i8> [[TMP4]], <vscale x 4 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8mf2x6(uint8_t *base, ptrdiff_t bstride, vuint8mf2x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv8i8.i64(<vscale x 8 x i8> [[TMP0]], <vscale x 8 x i8> [[TMP1]], <vscale x 8 x i8> [[TMP2]], <vscale x 8 x i8> [[TMP3]], <vscale x 8 x i8> [[TMP4]], <vscale x 8 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8m1x6(uint8_t *base, ptrdiff_t bstride, vuint8m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8mf8x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv1i8.i64(<vscale x 1 x i8> [[TMP0]], <vscale x 1 x i8> [[TMP1]], <vscale x 1 x i8> [[TMP2]], <vscale x 1 x i8> [[TMP3]], <vscale x 1 x i8> [[TMP4]], <vscale x 1 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8mf8x6_m(vbool64_t mask, int8_t *base, ptrdiff_t bstride, vint8mf8x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8mf4x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv2i8.i64(<vscale x 2 x i8> [[TMP0]], <vscale x 2 x i8> [[TMP1]], <vscale x 2 x i8> [[TMP2]], <vscale x 2 x i8> [[TMP3]], <vscale x 2 x i8> [[TMP4]], <vscale x 2 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8mf4x6_m(vbool32_t mask, int8_t *base, ptrdiff_t bstride, vint8mf4x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8mf2x6_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv4i8.i64(<vscale x 4 x i8> [[TMP0]], <vscale x 4 x i8> [[TMP1]], <vscale x 4 x i8> [[TMP2]], <vscale x 4 x i8> [[TMP3]], <vscale x 4 x i8> [[TMP4]], <vscale x 4 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8mf2x6_m(vbool16_t mask, int8_t *base, ptrdiff_t bstride, vint8mf2x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_i8m1x6_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv8i8.i64(<vscale x 8 x i8> [[TMP0]], <vscale x 8 x i8> [[TMP1]], <vscale x 8 x i8> [[TMP2]], <vscale x 8 x i8> [[TMP3]], <vscale x 8 x i8> [[TMP4]], <vscale x 8 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_i8m1x6_m(vbool8_t mask, int8_t *base, ptrdiff_t bstride, vint8m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8mf8x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv1i8.i64(<vscale x 1 x i8> [[TMP0]], <vscale x 1 x i8> [[TMP1]], <vscale x 1 x i8> [[TMP2]], <vscale x 1 x i8> [[TMP3]], <vscale x 1 x i8> [[TMP4]], <vscale x 1 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8mf8x6_m(vbool64_t mask, uint8_t *base, ptrdiff_t bstride, vuint8mf8x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8mf4x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv2i8.i64(<vscale x 2 x i8> [[TMP0]], <vscale x 2 x i8> [[TMP1]], <vscale x 2 x i8> [[TMP2]], <vscale x 2 x i8> [[TMP3]], <vscale x 2 x i8> [[TMP4]], <vscale x 2 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8mf4x6_m(vbool32_t mask, uint8_t *base, ptrdiff_t bstride, vuint8mf4x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8mf2x6_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv4i8.i64(<vscale x 4 x i8> [[TMP0]], <vscale x 4 x i8> [[TMP1]], <vscale x 4 x i8> [[TMP2]], <vscale x 4 x i8> [[TMP3]], <vscale x 4 x i8> [[TMP4]], <vscale x 4 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8mf2x6_m(vbool16_t mask, uint8_t *base, ptrdiff_t bstride, vuint8mf2x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e8_v_u8m1x6_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv8i8.i64(<vscale x 8 x i8> [[TMP0]], <vscale x 8 x i8> [[TMP1]], <vscale x 8 x i8> [[TMP2]], <vscale x 8 x i8> [[TMP3]], <vscale x 8 x i8> [[TMP4]], <vscale x 8 x i8> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e8_v_u8m1x6_m(vbool8_t mask, uint8_t *base, ptrdiff_t bstride, vuint8m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e8(mask, base, bstride, v_tuple, vl);
}

