// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target

// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svaddwb_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.saddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svaddwb_s16u11__SVInt16_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.saddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svint16_t test_svaddwb_s16(svint16_t op1, svint8_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_s16,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.saddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svaddwb_s32u11__SVInt32_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.saddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svint32_t test_svaddwb_s32(svint32_t op1, svint16_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_s32,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.saddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svaddwb_s64u11__SVInt64_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.saddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svint64_t test_svaddwb_s64(svint64_t op1, svint32_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_s64,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uaddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svaddwb_u16u12__SVUint16_tu11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uaddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svuint16_t test_svaddwb_u16(svuint16_t op1, svuint8_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_u16,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uaddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svaddwb_u32u12__SVUint32_tu12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uaddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svuint32_t test_svaddwb_u32(svuint32_t op1, svuint16_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_u32,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uaddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svaddwb_u64u12__SVUint64_tu12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uaddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[OP2:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svuint64_t test_svaddwb_u64(svuint64_t op1, svuint32_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_u64,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_n_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 16 x i8> poison, i8 [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 16 x i8> [[DOTSPLATINSERT]], <vscale x 16 x i8> poison, <vscale x 16 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.saddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[DOTSPLAT]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svaddwb_n_s16u11__SVInt16_ta(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 16 x i8> poison, i8 [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 16 x i8> [[DOTSPLATINSERT]], <vscale x 16 x i8> poison, <vscale x 16 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.saddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[DOTSPLAT]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svint16_t test_svaddwb_n_s16(svint16_t op1, int8_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_n_s16,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 8 x i16> poison, i16 [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 8 x i16> [[DOTSPLATINSERT]], <vscale x 8 x i16> poison, <vscale x 8 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.saddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[DOTSPLAT]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svaddwb_n_s32u11__SVInt32_ts(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 8 x i16> poison, i16 [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 8 x i16> [[DOTSPLATINSERT]], <vscale x 8 x i16> poison, <vscale x 8 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.saddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[DOTSPLAT]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svint32_t test_svaddwb_n_s32(svint32_t op1, int16_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_n_s32,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 4 x i32> poison, i32 [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 4 x i32> [[DOTSPLATINSERT]], <vscale x 4 x i32> poison, <vscale x 4 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.saddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[DOTSPLAT]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svaddwb_n_s64u11__SVInt64_ti(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 4 x i32> poison, i32 [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 4 x i32> [[DOTSPLATINSERT]], <vscale x 4 x i32> poison, <vscale x 4 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.saddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[DOTSPLAT]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svint64_t test_svaddwb_n_s64(svint64_t op1, int32_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_n_s64,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_n_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 16 x i8> poison, i8 [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 16 x i8> [[DOTSPLATINSERT]], <vscale x 16 x i8> poison, <vscale x 16 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uaddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[DOTSPLAT]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svaddwb_n_u16u12__SVUint16_th(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 16 x i8> poison, i8 [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 16 x i8> [[DOTSPLATINSERT]], <vscale x 16 x i8> poison, <vscale x 16 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uaddwb.nxv8i16(<vscale x 8 x i16> [[OP1:%.*]], <vscale x 16 x i8> [[DOTSPLAT]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svuint16_t test_svaddwb_n_u16(svuint16_t op1, uint8_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_n_u16,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 8 x i16> poison, i16 [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 8 x i16> [[DOTSPLATINSERT]], <vscale x 8 x i16> poison, <vscale x 8 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uaddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[DOTSPLAT]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svaddwb_n_u32u12__SVUint32_tt(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 8 x i16> poison, i16 [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 8 x i16> [[DOTSPLATINSERT]], <vscale x 8 x i16> poison, <vscale x 8 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uaddwb.nxv4i32(<vscale x 4 x i32> [[OP1:%.*]], <vscale x 8 x i16> [[DOTSPLAT]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svuint32_t test_svaddwb_n_u32(svuint32_t op1, uint16_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_n_u32,,)(op1, op2);
}

// CHECK-LABEL: @test_svaddwb_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 4 x i32> poison, i32 [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 4 x i32> [[DOTSPLATINSERT]], <vscale x 4 x i32> poison, <vscale x 4 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uaddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[DOTSPLAT]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svaddwb_n_u64u12__SVUint64_tj(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 4 x i32> poison, i32 [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[DOTSPLAT:%.*]] = shufflevector <vscale x 4 x i32> [[DOTSPLATINSERT]], <vscale x 4 x i32> poison, <vscale x 4 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uaddwb.nxv2i64(<vscale x 2 x i64> [[OP1:%.*]], <vscale x 4 x i32> [[DOTSPLAT]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svuint64_t test_svaddwb_n_u64(svuint64_t op1, uint32_t op2)
{
  return SVE_ACLE_FUNC(svaddwb,_n_u64,,)(op1, op2);
}
