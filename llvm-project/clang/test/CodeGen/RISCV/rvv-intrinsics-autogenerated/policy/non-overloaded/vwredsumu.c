// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8mf8_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv1i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 1 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8mf8_u16m1_tu(vuint16m1_t maskedoff, vuint8mf8_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8mf8_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8mf4_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv2i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 2 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8mf4_u16m1_tu(vuint16m1_t maskedoff, vuint8mf4_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8mf4_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8mf2_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv4i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 4 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8mf2_u16m1_tu(vuint16m1_t maskedoff, vuint8mf2_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8mf2_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m1_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv8i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 8 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m1_u16m1_tu(vuint16m1_t maskedoff, vuint8m1_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m1_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m2_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 16 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv16i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 16 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m2_u16m1_tu(vuint16m1_t maskedoff, vuint8m2_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m2_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m4_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 32 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv32i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 32 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m4_u16m1_tu(vuint16m1_t maskedoff, vuint8m4_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m4_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m8_u16m1_tu
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 64 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.nxv4i16.nxv64i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 64 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m8_u16m1_tu(vuint16m1_t maskedoff, vuint8m8_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m8_u16m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16mf4_u32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.nxv2i32.nxv1i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 1 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16mf4_u32m1_tu(vuint32m1_t maskedoff, vuint16mf4_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16mf4_u32m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16mf2_u32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.nxv2i32.nxv2i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 2 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16mf2_u32m1_tu(vuint32m1_t maskedoff, vuint16mf2_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16mf2_u32m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m1_u32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.nxv2i32.nxv4i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 4 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m1_u32m1_tu(vuint32m1_t maskedoff, vuint16m1_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m1_u32m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m2_u32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.nxv2i32.nxv8i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 8 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m2_u32m1_tu(vuint32m1_t maskedoff, vuint16m2_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m2_u32m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m4_u32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.nxv2i32.nxv16i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 16 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m4_u32m1_tu(vuint32m1_t maskedoff, vuint16m4_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m4_u32m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m8_u32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 32 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.nxv2i32.nxv32i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 32 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m8_u32m1_tu(vuint32m1_t maskedoff, vuint16m8_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m8_u32m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32mf2_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.nxv1i64.nxv1i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32mf2_u64m1_tu(vuint64m1_t maskedoff, vuint32mf2_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32mf2_u64m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m1_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.nxv1i64.nxv2i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 2 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m1_u64m1_tu(vuint64m1_t maskedoff, vuint32m1_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m1_u64m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m2_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.nxv1i64.nxv4i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 4 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m2_u64m1_tu(vuint64m1_t maskedoff, vuint32m2_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m2_u64m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m4_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.nxv1i64.nxv8i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 8 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m4_u64m1_tu(vuint64m1_t maskedoff, vuint32m4_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m4_u64m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m8_u64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 16 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.nxv1i64.nxv16i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 16 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m8_u64m1_tu(vuint64m1_t maskedoff, vuint32m8_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m8_u64m1_tu(maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8mf8_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv1i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 1 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8mf8_u16m1_tum(vbool64_t mask, vuint16m1_t maskedoff, vuint8mf8_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8mf8_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8mf4_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv2i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 2 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8mf4_u16m1_tum(vbool32_t mask, vuint16m1_t maskedoff, vuint8mf4_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8mf4_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8mf2_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv4i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 4 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8mf2_u16m1_tum(vbool16_t mask, vuint16m1_t maskedoff, vuint8mf2_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8mf2_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m1_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv8i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 8 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m1_u16m1_tum(vbool8_t mask, vuint16m1_t maskedoff, vuint8m1_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m1_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m2_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 16 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv16i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 16 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 16 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m2_u16m1_tum(vbool4_t mask, vuint16m1_t maskedoff, vuint8m2_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m2_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m4_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 32 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv32i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 32 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 32 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m4_u16m1_tum(vbool2_t mask, vuint16m1_t maskedoff, vuint8m4_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m4_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwredsumu_vs_u8m8_u16m1_tum
// CHECK-RV64-SAME: (<vscale x 64 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 64 x i8> [[VECTOR:%.*]], <vscale x 4 x i16> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwredsumu.mask.nxv4i16.nxv64i8.i64(<vscale x 4 x i16> [[MASKEDOFF]], <vscale x 64 x i8> [[VECTOR]], <vscale x 4 x i16> [[SCALAR]], <vscale x 64 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwredsumu_vs_u8m8_u16m1_tum(vbool1_t mask, vuint16m1_t maskedoff, vuint8m8_t vector, vuint16m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u8m8_u16m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16mf4_u32m1_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.mask.nxv2i32.nxv1i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 1 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16mf4_u32m1_tum(vbool64_t mask, vuint32m1_t maskedoff, vuint16mf4_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16mf4_u32m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16mf2_u32m1_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.mask.nxv2i32.nxv2i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 2 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16mf2_u32m1_tum(vbool32_t mask, vuint32m1_t maskedoff, vuint16mf2_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16mf2_u32m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m1_u32m1_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.mask.nxv2i32.nxv4i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 4 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m1_u32m1_tum(vbool16_t mask, vuint32m1_t maskedoff, vuint16m1_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m1_u32m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m2_u32m1_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.mask.nxv2i32.nxv8i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 8 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m2_u32m1_tum(vbool8_t mask, vuint32m1_t maskedoff, vuint16m2_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m2_u32m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m4_u32m1_tum
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.mask.nxv2i32.nxv16i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 16 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], <vscale x 16 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m4_u32m1_tum(vbool4_t mask, vuint32m1_t maskedoff, vuint16m4_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m4_u32m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwredsumu_vs_u16m8_u32m1_tum
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 32 x i16> [[VECTOR:%.*]], <vscale x 2 x i32> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwredsumu.mask.nxv2i32.nxv32i16.i64(<vscale x 2 x i32> [[MASKEDOFF]], <vscale x 32 x i16> [[VECTOR]], <vscale x 2 x i32> [[SCALAR]], <vscale x 32 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwredsumu_vs_u16m8_u32m1_tum(vbool2_t mask, vuint32m1_t maskedoff, vuint16m8_t vector, vuint32m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u16m8_u32m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32mf2_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.mask.nxv1i64.nxv1i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 1 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32mf2_u64m1_tum(vbool64_t mask, vuint64m1_t maskedoff, vuint32mf2_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32mf2_u64m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m1_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.mask.nxv1i64.nxv2i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 2 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m1_u64m1_tum(vbool32_t mask, vuint64m1_t maskedoff, vuint32m1_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m1_u64m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m2_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.mask.nxv1i64.nxv4i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 4 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m2_u64m1_tum(vbool16_t mask, vuint64m1_t maskedoff, vuint32m2_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m2_u64m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m4_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.mask.nxv1i64.nxv8i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 8 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m4_u64m1_tum(vbool8_t mask, vuint64m1_t maskedoff, vuint32m4_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m4_u64m1_tum(mask, maskedoff, vector, scalar, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwredsumu_vs_u32m8_u64m1_tum
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 16 x i32> [[VECTOR:%.*]], <vscale x 1 x i64> [[SCALAR:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwredsumu.mask.nxv1i64.nxv16i32.i64(<vscale x 1 x i64> [[MASKEDOFF]], <vscale x 16 x i32> [[VECTOR]], <vscale x 1 x i64> [[SCALAR]], <vscale x 16 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwredsumu_vs_u32m8_u64m1_tum(vbool4_t mask, vuint64m1_t maskedoff, vuint32m8_t vector, vuint64m1_t scalar, size_t vl) {
  return __riscv_vwredsumu_vs_u32m8_u64m1_tum(mask, maskedoff, vector, scalar, vl);
}

