// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 \
// RUN:   -Werror -emit-llvm -disable-O0-optnone -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 \
// RUN:   -Werror -emit-llvm -disable-O0-optnone -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 \
// RUN:   -Werror -emit-llvm -disable-O0-optnone -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 \
// RUN:   -Werror -emit-llvm -disable-O0-optnone -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 \
// RUN:   -S -disable-O0-optnone -Werror -Wall -o /dev/null %s


#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1, A2_UNUSED, A3, A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1, A2, A3, A4) A1##A2##A3##A4
#endif

// LD1W

// CHECK-LABEL: define dso_local <vscale x 4 x i32> @test_svld1uwq_u32
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 4 x i32> @_Z17test_svld1uwq_u32u10__SVBool_tPKj
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0:[0-9]+]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svuint32_t test_svld1uwq_u32(svbool_t pred, uint32_t const * base) {
  return SVE_ACLE_FUNC(svld1uwq, _u32, , )(pred, base);
}

// CHECK-LABEL: define dso_local <vscale x 4 x i32> @test_svld1uwq_vnum_u32
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul nsw i64 [[TMP1]], -32
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP3]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 4 x i32> @_Z22test_svld1uwq_vnum_u32u10__SVBool_tPKj
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul nsw i64 [[TMP1]], -32
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP3]]
//
svuint32_t test_svld1uwq_vnum_u32(svbool_t pred, uint32_t const * base) {
  return SVE_ACLE_FUNC(svld1uwq_vnum, _u32, , )(pred, base, -8);
}

// CHECK-LABEL: define dso_local <vscale x 4 x i32> @test_svld1uwq_s32
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 4 x i32> @_Z17test_svld1uwq_s32u10__SVBool_tPKi
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svint32_t test_svld1uwq_s32(svbool_t pred, int32_t const * base) {
  return SVE_ACLE_FUNC(svld1uwq, _s32, , )(pred, base);
}

// CHECK-LABEL: define dso_local <vscale x 4 x i32> @test_svld1uwq_vnum_s32
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul nuw nsw i64 [[TMP1]], 28
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP3]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 4 x i32> @_Z22test_svld1uwq_vnum_s32u10__SVBool_tPKi
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul nuw nsw i64 [[TMP1]], 28
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.ld1uwq.nxv4i32(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP3]]
//
svint32_t test_svld1uwq_vnum_s32(svbool_t pred, int32_t const * base) {
  return SVE_ACLE_FUNC(svld1uwq_vnum, _s32, , )(pred, base, 7);
}

// CHECK-LABEL: define dso_local <vscale x 4 x float> @test_svld1uwq_f32
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sve.ld1uwq.nxv4f32(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CHECK-NEXT:    ret <vscale x 4 x float> [[TMP1]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 4 x float> @_Z17test_svld1uwq_f32u10__SVBool_tPKf
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sve.ld1uwq.nxv4f32(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x float> [[TMP1]]
//
svfloat32_t test_svld1uwq_f32(svbool_t pred, float32_t const * base) {
  return SVE_ACLE_FUNC(svld1uwq, _f32, , )(pred, base);
}

// CHECK-LABEL: define dso_local <vscale x 4 x float> @test_svld1uwq_vnum_f32
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul nsw i64 [[TMP1]], -32
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sve.ld1uwq.nxv4f32(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CHECK-NEXT:    ret <vscale x 4 x float> [[TMP3]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 4 x float> @_Z22test_svld1uwq_vnum_f32u10__SVBool_tPKf
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul nsw i64 [[TMP1]], -32
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sve.ld1uwq.nxv4f32(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x float> [[TMP3]]
//
svfloat32_t test_svld1uwq_vnum_f32(svbool_t pred, float32_t const * base) {
  return SVE_ACLE_FUNC(svld1uwq_vnum, _f32, , )(pred, base, -8);
}


// LD1D

// CHECK-LABEL: define dso_local <vscale x 2 x i64> @test_svld1udq_u64
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 2 x i64> @_Z17test_svld1udq_u64u10__SVBool_tPKm
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svuint64_t test_svld1udq_u64(svbool_t pred, uint64_t const * base) {
  return SVE_ACLE_FUNC(svld1udq, _u64, , )(pred, base);
}

// CHECK-LABEL: define dso_local <vscale x 2 x i64> @test_svld1udq_vnum_u64
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul nuw nsw i64 [[TMP1]], 56
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 2 x i64> @_Z22test_svld1udq_vnum_u64u10__SVBool_tPKm
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul nuw nsw i64 [[TMP1]], 56
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
svuint64_t test_svld1udq_vnum_u64(svbool_t pred, uint64_t const * base) {
  return SVE_ACLE_FUNC(svld1udq_vnum, _u64, , )(pred, base, 7);
}

// CHECK-LABEL: define dso_local <vscale x 2 x i64> @test_svld1udq_s64
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 2 x i64> @_Z17test_svld1udq_s64u10__SVBool_tPKl
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svint64_t test_svld1udq_s64(svbool_t pred, int64_t const * base) {
  return SVE_ACLE_FUNC(svld1udq, _s64, , )(pred, base);
}

// CHECK-LABEL: define dso_local <vscale x 2 x i64> @test_svld1udq_vnum_s64
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul nsw i64 [[TMP1]], -64
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 2 x i64> @_Z22test_svld1udq_vnum_s64u10__SVBool_tPKl
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul nsw i64 [[TMP1]], -64
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.ld1udq.nxv2i64(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
svint64_t test_svld1udq_vnum_s64(svbool_t pred, int64_t const * base) {
  return SVE_ACLE_FUNC(svld1udq_vnum, _s64, , )(pred, base, -8);
}

// CHECK-LABEL: define dso_local <vscale x 2 x double> @test_svld1udq_f64
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.aarch64.sve.ld1udq.nxv2f64(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CHECK-NEXT:    ret <vscale x 2 x double> [[TMP1]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 2 x double> @_Z17test_svld1udq_f64u10__SVBool_tPKd
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.aarch64.sve.ld1udq.nxv2f64(<vscale x 1 x i1> [[TMP0]], ptr [[BASE]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x double> [[TMP1]]
//
svfloat64_t test_svld1udq_f64(svbool_t pred, float64_t const * base) {
  return SVE_ACLE_FUNC(svld1udq, _f64, , )(pred, base);
}

// CHECK-LABEL: define dso_local <vscale x 2 x double> @test_svld1udq_vnum_f64
// CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul nuw nsw i64 [[TMP1]], 56
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.aarch64.sve.ld1udq.nxv2f64(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CHECK-NEXT:    ret <vscale x 2 x double> [[TMP3]]
//
// CPP-CHECK-LABEL: define dso_local <vscale x 2 x double> @_Z22test_svld1udq_vnum_f64u10__SVBool_tPKd
// CPP-CHECK-SAME: (<vscale x 16 x i1> [[PRED:%.*]], ptr noundef [[BASE:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 1 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv1i1(<vscale x 16 x i1> [[PRED]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul nuw nsw i64 [[TMP1]], 56
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr i8, ptr [[BASE]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.aarch64.sve.ld1udq.nxv2f64(<vscale x 1 x i1> [[TMP0]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x double> [[TMP3]]
//
svfloat64_t test_svld1udq_vnum_f64(svbool_t pred, float64_t const * base) {
  return SVE_ACLE_FUNC(svld1udq_vnum, _f64, , )(pred, base, 7);
}
