// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

#ifdef __ARM_FEATURE_SME
#define ATTR __arm_streaming
#else
#define ATTR
#endif

// CHECK-LABEL: @test_svset2_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i8> @llvm.vector.insert.nxv32i8.nxv16i8(<vscale x 32 x i8> [[TUPLE:%.*]], <vscale x 16 x i8> [[X:%.*]], i64 16)
// CHECK-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svset2_s810svint8x2_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i8> @llvm.vector.insert.nxv32i8.nxv16i8(<vscale x 32 x i8> [[TUPLE:%.*]], <vscale x 16 x i8> [[X:%.*]], i64 16)
// CPP-CHECK-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
svint8x2_t test_svset2_s8(svint8x2_t tuple, svint8_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_s8,,)(tuple, 1, x);
}

// CHECK-LABEL: @test_svset2_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i16> @llvm.vector.insert.nxv16i16.nxv8i16(<vscale x 16 x i16> [[TUPLE:%.*]], <vscale x 8 x i16> [[X:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_s1611svint16x2_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i16> @llvm.vector.insert.nxv16i16.nxv8i16(<vscale x 16 x i16> [[TUPLE:%.*]], <vscale x 8 x i16> [[X:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
svint16x2_t test_svset2_s16(svint16x2_t tuple, svint16_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_s16,,)(tuple, 0, x);
}

// CHECK-LABEL: @test_svset2_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i32> @llvm.vector.insert.nxv8i32.nxv4i32(<vscale x 8 x i32> [[TUPLE:%.*]], <vscale x 4 x i32> [[X:%.*]], i64 4)
// CHECK-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_s3211svint32x2_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i32> @llvm.vector.insert.nxv8i32.nxv4i32(<vscale x 8 x i32> [[TUPLE:%.*]], <vscale x 4 x i32> [[X:%.*]], i64 4)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
svint32x2_t test_svset2_s32(svint32x2_t tuple, svint32_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_s32,,)(tuple, 1, x);
}

// CHECK-LABEL: @test_svset2_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i64> @llvm.vector.insert.nxv4i64.nxv2i64(<vscale x 4 x i64> [[TUPLE:%.*]], <vscale x 2 x i64> [[X:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_s6411svint64x2_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i64> @llvm.vector.insert.nxv4i64.nxv2i64(<vscale x 4 x i64> [[TUPLE:%.*]], <vscale x 2 x i64> [[X:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
svint64x2_t test_svset2_s64(svint64x2_t tuple, svint64_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_s64,,)(tuple, 0, x);
}

// CHECK-LABEL: @test_svset2_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i8> @llvm.vector.insert.nxv32i8.nxv16i8(<vscale x 32 x i8> [[TUPLE:%.*]], <vscale x 16 x i8> [[X:%.*]], i64 16)
// CHECK-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svset2_u811svuint8x2_tu11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i8> @llvm.vector.insert.nxv32i8.nxv16i8(<vscale x 32 x i8> [[TUPLE:%.*]], <vscale x 16 x i8> [[X:%.*]], i64 16)
// CPP-CHECK-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
svuint8x2_t test_svset2_u8(svuint8x2_t tuple, svuint8_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_u8,,)(tuple, 1, x);
}

// CHECK-LABEL: @test_svset2_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i16> @llvm.vector.insert.nxv16i16.nxv8i16(<vscale x 16 x i16> [[TUPLE:%.*]], <vscale x 8 x i16> [[X:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_u1612svuint16x2_tu12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i16> @llvm.vector.insert.nxv16i16.nxv8i16(<vscale x 16 x i16> [[TUPLE:%.*]], <vscale x 8 x i16> [[X:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
svuint16x2_t test_svset2_u16(svuint16x2_t tuple, svuint16_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_u16,,)(tuple, 0, x);
}

// CHECK-LABEL: @test_svset2_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i32> @llvm.vector.insert.nxv8i32.nxv4i32(<vscale x 8 x i32> [[TUPLE:%.*]], <vscale x 4 x i32> [[X:%.*]], i64 4)
// CHECK-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_u3212svuint32x2_tu12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i32> @llvm.vector.insert.nxv8i32.nxv4i32(<vscale x 8 x i32> [[TUPLE:%.*]], <vscale x 4 x i32> [[X:%.*]], i64 4)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
svuint32x2_t test_svset2_u32(svuint32x2_t tuple, svuint32_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_u32,,)(tuple, 1, x);
}

// CHECK-LABEL: @test_svset2_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i64> @llvm.vector.insert.nxv4i64.nxv2i64(<vscale x 4 x i64> [[TUPLE:%.*]], <vscale x 2 x i64> [[X:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_u6412svuint64x2_tu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i64> @llvm.vector.insert.nxv4i64.nxv2i64(<vscale x 4 x i64> [[TUPLE:%.*]], <vscale x 2 x i64> [[X:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
svuint64x2_t test_svset2_u64(svuint64x2_t tuple, svuint64_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_u64,,)(tuple, 0, x);
}

// CHECK-LABEL: @test_svset2_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x half> @llvm.vector.insert.nxv16f16.nxv8f16(<vscale x 16 x half> [[TUPLE:%.*]], <vscale x 8 x half> [[X:%.*]], i64 8)
// CHECK-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_f1613svfloat16x2_tu13__SVFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x half> @llvm.vector.insert.nxv16f16.nxv8f16(<vscale x 16 x half> [[TUPLE:%.*]], <vscale x 8 x half> [[X:%.*]], i64 8)
// CPP-CHECK-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
svfloat16x2_t test_svset2_f16(svfloat16x2_t tuple, svfloat16_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_f16,,)(tuple, 1, x);
}

// CHECK-LABEL: @test_svset2_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TUPLE:%.*]], <vscale x 4 x float> [[X:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_f3213svfloat32x2_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TUPLE:%.*]], <vscale x 4 x float> [[X:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
svfloat32x2_t test_svset2_f32(svfloat32x2_t tuple, svfloat32_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_f32,,)(tuple, 0, x);
}

// CHECK-LABEL: @test_svset2_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x double> @llvm.vector.insert.nxv4f64.nxv2f64(<vscale x 4 x double> [[TUPLE:%.*]], <vscale x 2 x double> [[X:%.*]], i64 2)
// CHECK-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_f6413svfloat64x2_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x double> @llvm.vector.insert.nxv4f64.nxv2f64(<vscale x 4 x double> [[TUPLE:%.*]], <vscale x 2 x double> [[X:%.*]], i64 2)
// CPP-CHECK-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
svfloat64x2_t test_svset2_f64(svfloat64x2_t tuple, svfloat64_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_f64,,)(tuple, 1, x);
}
