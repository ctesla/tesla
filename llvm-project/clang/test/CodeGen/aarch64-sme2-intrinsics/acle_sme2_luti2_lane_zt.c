// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py

// REQUIRES: aarch64-registered-target

// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sme.h>


// CHECK-LABEL: @test_svluti2_lane_zt_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sme.luti2.lane.zt.nxv16i8(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z23test_svluti2_lane_zt_u8u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sme.luti2.lane.zt.nxv16i8(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svuint8_t test_svluti2_lane_zt_u8(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_u8(0, zn, 15);
}


// CHECK-LABEL: @test_svluti2_lane_zt_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sme.luti2.lane.zt.nxv16i8(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z23test_svluti2_lane_zt_s8u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sme.luti2.lane.zt.nxv16i8(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svluti2_lane_zt_s8(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_s8(0, zn, 15);
}

// CHECK-LABEL: @test_svluti2_lane_zt_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sme.luti2.lane.zt.nxv8i16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z24test_svluti2_lane_zt_u16u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sme.luti2.lane.zt.nxv8i16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svuint16_t test_svluti2_lane_zt_u16(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_u16(0, zn, 15);
}


// CHECK-LABEL: @test_svluti2_lane_zt_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sme.luti2.lane.zt.nxv8i16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z24test_svluti2_lane_zt_s16u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sme.luti2.lane.zt.nxv8i16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svint16_t test_svluti2_lane_zt_s16(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_s16(0, zn, 15);
}

// CHECK-LABEL: @test_svluti2_lane_zt_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.aarch64.sme.luti2.lane.zt.nxv8f16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z24test_svluti2_lane_zt_f16u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.aarch64.sme.luti2.lane.zt.nxv8f16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
svfloat16_t test_svluti2_lane_zt_f16(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_f16(0, zn, 15);
}

// CHECK-LABEL: @test_svluti2_lane_zt_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.aarch64.sme.luti2.lane.zt.nxv8bf16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z25test_svluti2_lane_zt_bf16u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.aarch64.sme.luti2.lane.zt.nxv8bf16(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
svbfloat16_t test_svluti2_lane_zt_bf16(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_bf16(0, zn, 15);
}

// CHECK-LABEL: @test_svluti2_lane_zt_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sme.luti2.lane.zt.nxv4i32(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z24test_svluti2_lane_zt_u32u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sme.luti2.lane.zt.nxv4i32(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svuint32_t test_svluti2_lane_zt_u32(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_u32(0, zn, 15);
}

// CHECK-LABEL: @test_svluti2_lane_zt_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sme.luti2.lane.zt.nxv4i32(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z24test_svluti2_lane_zt_s32u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sme.luti2.lane.zt.nxv4i32(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svint32_t test_svluti2_lane_zt_s32(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_s32(0, zn, 15);
}

// CHECK-LABEL: @test_svluti2_lane_zt_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sme.luti2.lane.zt.nxv4f32(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CHECK-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z24test_svluti2_lane_zt_f32u11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.aarch64.sme.luti2.lane.zt.nxv4f32(i32 0, <vscale x 16 x i8> [[ZN:%.*]], i32 15)
// CPP-CHECK-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
svfloat32_t test_svluti2_lane_zt_f32(svuint8_t zn) __arm_streaming __arm_in("zt0") {
  return svluti2_lane_zt_f32(0, zn, 15);
}
