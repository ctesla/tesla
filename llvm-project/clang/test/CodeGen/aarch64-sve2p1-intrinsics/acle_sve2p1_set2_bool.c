// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s\
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sve2 -target-feature +sve2p1 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

// REQUIRES: aarch64-registered-target

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

// CHECK-LABEL: @test_svset2_b_0(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> [[TUPLE:%.*]], <vscale x 16 x i1> [[X:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_b_010svboolx2_tu10__SVBool_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> [[TUPLE:%.*]], <vscale x 16 x i1> [[X:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
svboolx2_t test_svset2_b_0(svboolx2_t tuple, svbool_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_b,,)(tuple, 0, x);
}

// CHECK-LABEL: @test_svset2_b_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> [[TUPLE:%.*]], <vscale x 16 x i1> [[X:%.*]], i64 16)
// CHECK-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z15test_svset2_b_110svboolx2_tu10__SVBool_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> [[TUPLE:%.*]], <vscale x 16 x i1> [[X:%.*]], i64 16)
// CPP-CHECK-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
svboolx2_t test_svset2_b_1(svboolx2_t tuple, svbool_t x) ATTR
{
  return SVE_ACLE_FUNC(svset2,_b,,)(tuple, 1, x);
}

