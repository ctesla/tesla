// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -fclang-abi-compat=latest -target-feature +f64mm -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -target-feature +f64mm -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -fclang-abi-compat=latest -target-feature +f64mm -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -target-feature +f64mm -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK

// REQUIRES: aarch64-registered-target

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1, A2_UNUSED, A3, A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1, A2, A3, A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svtrn2_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.trn2q.nxv16i8(<vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svtrn2_s8u10__SVInt8_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.trn2q.nxv16i8(<vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svtrn2_s8(svint8_t op1, svint8_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _s8, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.trn2q.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_s16u11__SVInt16_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.trn2q.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svint16_t test_svtrn2_s16(svint16_t op1, svint16_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _s16, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.trn2q.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_s32u11__SVInt32_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.trn2q.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svint32_t test_svtrn2_s32(svint32_t op1, svint32_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _s32, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.trn2q.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_s64u11__SVInt64_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.trn2q.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svint64_t test_svtrn2_s64(svint64_t op1, svint64_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _s64, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.trn2q.nxv16i8(<vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svtrn2_u8u11__SVUint8_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.trn2q.nxv16i8(<vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svuint8_t test_svtrn2_u8(svuint8_t op1, svuint8_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _u8, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.trn2q.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_u16u12__SVUint16_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.trn2q.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svuint16_t test_svtrn2_u16(svuint16_t op1, svuint16_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _u16, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.trn2q.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_u32u12__SVUint32_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.trn2q.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svuint32_t test_svtrn2_u32(svuint32_t op1, svuint32_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _u32, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.trn2q.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_u64u12__SVUint64_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.trn2q.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svuint64_t test_svtrn2_u64(svuint64_t op1, svuint64_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _u64, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.aarch64.sve.trn2q.nxv8f16(<vscale x 8 x half> [[OP1:%.*]], <vscale x 8 x half> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_f16u13__SVFloat16_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.aarch64.sve.trn2q.nxv8f16(<vscale x 8 x half> [[OP1:%.*]], <vscale x 8 x half> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
svfloat16_t test_svtrn2_f16(svfloat16_t op1, svfloat16_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _f16, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sve.trn2q.nxv4f32(<vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_f32u13__SVFloat32_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sve.trn2q.nxv4f32(<vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
svfloat32_t test_svtrn2_f32(svfloat32_t op1, svfloat32_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _f32, , )(op1, op2);
}

// CHECK-LABEL: @test_svtrn2_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.aarch64.sve.trn2q.nxv2f64(<vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svtrn2_f64u13__SVFloat64_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.aarch64.sve.trn2q.nxv2f64(<vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
svfloat64_t test_svtrn2_f64(svfloat64_t op1, svfloat64_t op2) {
  return SVE_ACLE_FUNC(svtrn2q, _f64, , )(op1, op2);
}
