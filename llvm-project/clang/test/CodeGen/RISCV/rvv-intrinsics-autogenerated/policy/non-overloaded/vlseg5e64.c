// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @test_vlseg5e64_v_f64m1x5_tu
// CHECK-RV64-SAME: ({ <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.nxv1f64.i64(<vscale x 1 x double> [[TMP0]], <vscale x 1 x double> [[TMP1]], <vscale x 1 x double> [[TMP2]], <vscale x 1 x double> [[TMP3]], <vscale x 1 x double> [[TMP4]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP5]]
//
vfloat64m1x5_t test_vlseg5e64_v_f64m1x5_tu(vfloat64m1x5_t maskedoff_tuple, const double *base, size_t vl) {
  return __riscv_vlseg5e64_v_f64m1x5_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_i64m1x5_tu
// CHECK-RV64-SAME: ({ <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vint64m1x5_t test_vlseg5e64_v_i64m1x5_tu(vint64m1x5_t maskedoff_tuple, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_i64m1x5_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_u64m1x5_tu
// CHECK-RV64-SAME: ({ <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vuint64m1x5_t test_vlseg5e64_v_u64m1x5_tu(vuint64m1x5_t maskedoff_tuple, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_u64m1x5_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @test_vlseg5e64_v_f64m1x5_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.mask.nxv1f64.i64(<vscale x 1 x double> [[TMP0]], <vscale x 1 x double> [[TMP1]], <vscale x 1 x double> [[TMP2]], <vscale x 1 x double> [[TMP3]], <vscale x 1 x double> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP5]]
//
vfloat64m1x5_t test_vlseg5e64_v_f64m1x5_tum(vbool64_t mask, vfloat64m1x5_t maskedoff_tuple, const double *base, size_t vl) {
  return __riscv_vlseg5e64_v_f64m1x5_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_i64m1x5_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vint64m1x5_t test_vlseg5e64_v_i64m1x5_tum(vbool64_t mask, vint64m1x5_t maskedoff_tuple, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_i64m1x5_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_u64m1x5_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vuint64m1x5_t test_vlseg5e64_v_u64m1x5_tum(vbool64_t mask, vuint64m1x5_t maskedoff_tuple, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_u64m1x5_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @test_vlseg5e64_v_f64m1x5_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.mask.nxv1f64.i64(<vscale x 1 x double> [[TMP0]], <vscale x 1 x double> [[TMP1]], <vscale x 1 x double> [[TMP2]], <vscale x 1 x double> [[TMP3]], <vscale x 1 x double> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP5]]
//
vfloat64m1x5_t test_vlseg5e64_v_f64m1x5_tumu(vbool64_t mask, vfloat64m1x5_t maskedoff_tuple, const double *base, size_t vl) {
  return __riscv_vlseg5e64_v_f64m1x5_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_i64m1x5_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vint64m1x5_t test_vlseg5e64_v_i64m1x5_tumu(vbool64_t mask, vint64m1x5_t maskedoff_tuple, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_i64m1x5_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_u64m1x5_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vuint64m1x5_t test_vlseg5e64_v_u64m1x5_tumu(vbool64_t mask, vuint64m1x5_t maskedoff_tuple, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_u64m1x5_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @test_vlseg5e64_v_f64m1x5_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.mask.nxv1f64.i64(<vscale x 1 x double> [[TMP0]], <vscale x 1 x double> [[TMP1]], <vscale x 1 x double> [[TMP2]], <vscale x 1 x double> [[TMP3]], <vscale x 1 x double> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP5]]
//
vfloat64m1x5_t test_vlseg5e64_v_f64m1x5_mu(vbool64_t mask, vfloat64m1x5_t maskedoff_tuple, const double *base, size_t vl) {
  return __riscv_vlseg5e64_v_f64m1x5_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_i64m1x5_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vint64m1x5_t test_vlseg5e64_v_i64m1x5_mu(vbool64_t mask, vint64m1x5_t maskedoff_tuple, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_i64m1x5_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @test_vlseg5e64_v_u64m1x5_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[MASKEDOFF_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP5]]
//
vuint64m1x5_t test_vlseg5e64_v_u64m1x5_mu(vbool64_t mask, vuint64m1x5_t maskedoff_tuple, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_v_u64m1x5_mu(mask, maskedoff_tuple, base, vl);
}

