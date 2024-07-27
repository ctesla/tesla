// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 3
// RUN: %clang_cc1 -triple=x86_64 -emit-llvm -o - -std=c23 %s | FileCheck %s

/* WG14 N2819: No
 * Disambiguate the storage class of some compound literals
 */

int *escaped;
// CHECK-LABEL: define dso_local i32 @f(
// CHECK-SAME: ptr noundef [[PTR:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[PTR_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[PTR]], ptr [[PTR_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[PTR_ADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP0]], ptr @escaped, align 8
// CHECK-NEXT:    ret i32 1
//
int f(int *ptr) { escaped = ptr; return 1; }

// CHECK-LABEL: define dso_local i32 @g(
// CHECK-SAME: ptr noundef [[PARA:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[PARA_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[PARA]], ptr [[PARA_ADDR]], align 8
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @f(ptr noundef @.compoundliteral)
// CHECK-NEXT:    [[TMP0:%.*]] = zext i32 [[CALL]] to i64
// CHECK-NEXT:    ret i32 0
//
// FIXME: notice the we are using the global .compoundliteral object, not
// allocating a new object on each call to g(). That's what was clarified by
// N2819.
int g(char *para [f(( int [27]) { 0 })]) {
  return 0;
}

// CHECK-LABEL: define dso_local i32 @main(
// CHECK-SAME: ) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store i32 0, ptr [[RETVAL]], align 4
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @g(ptr noundef null)
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr @escaped, align 8
// CHECK-NEXT:    store i32 12, ptr [[TMP0]], align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load ptr, ptr @escaped, align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[TMP1]], align 4
// CHECK-NEXT:    ret i32 [[TMP2]]
//
int main() {
  // Sets 'escaped' to the address of the array created by the compound literal.
  g(nullptr);

  // The lifetime of that object should have ended when g() returned, so this
  // should be a use-after-free.
  *escaped = 12;
  return *escaped;
}

