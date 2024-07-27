// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 5
// RUN: %clang_cc1 -triple x86_64-linux-gnu -target-cpu core2 %s -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 -triple i686-linux-gnu -target-cpu core2 %s -emit-llvm -o - | FileCheck %s


// CHECK-LABEL: define dso_local i32 @test_int_inc(
// CHECK-SAME: ) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[TMP0:%.*]] = atomicrmw add ptr @test_int_inc.n, i32 1 seq_cst, align 4
// CHECK-NEXT:    ret i32 [[TMP0]]
//
int test_int_inc()
{
    static _Atomic int n;
    return n++;
}

// CHECK-LABEL: define dso_local float @test_float_post_inc(
// CHECK-SAME: ) #[[ATTR0]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[TMP0:%.*]] = atomicrmw fadd ptr @test_float_post_inc.n, float 1.000000e+00 seq_cst, align 4
// CHECK-NEXT:    ret float [[TMP0]]
//
float test_float_post_inc()
{
    static _Atomic float n;
    return n++;
}

// CHECK-LABEL: define dso_local float @test_float_post_dc(
// CHECK-SAME: ) #[[ATTR0]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[TMP0:%.*]] = atomicrmw fsub ptr @test_float_post_dc.n, float 1.000000e+00 seq_cst, align 4
// CHECK-NEXT:    ret float [[TMP0]]
//
float test_float_post_dc()
{
    static _Atomic float n;
    return n--;
}

// CHECK-LABEL: define dso_local float @test_float_pre_dc(
// CHECK-SAME: ) #[[ATTR0]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[TMP0:%.*]] = atomicrmw fsub ptr @test_float_pre_dc.n, float 1.000000e+00 seq_cst, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = fsub float [[TMP0]], 1.000000e+00
// CHECK-NEXT:    ret float [[TMP1]]
//
float test_float_pre_dc()
{
    static _Atomic float n;
    return --n;
}

// CHECK-LABEL: define dso_local float @test_float_pre_inc(
// CHECK-SAME: ) #[[ATTR0]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[TMP0:%.*]] = atomicrmw fadd ptr @test_float_pre_inc.n, float 1.000000e+00 seq_cst, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = fadd float [[TMP0]], 1.000000e+00
// CHECK-NEXT:    ret float [[TMP1]]
//
float test_float_pre_inc()
{
    static _Atomic float n;
    return ++n;
}
