// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 3
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv32 -O2 -emit-llvm %s -o - \
// RUN:     | FileCheck %s
// RUN: %clang_cc1 -triple riscv64 -O2 -emit-llvm %s -o - \
// RUN:     | FileCheck %s

// Test RISC-V specific clobbered registers in inline assembly.

// CHECK-LABEL: define {{.*}} void @test_fflags
// CHECK:    tail call void asm sideeffect "", "~{fflags}"()
void test_fflags(void) {
  asm volatile ("" :::"fflags");
}

// CHECK-LABEL: define {{.*}} void @test_frm
// CHECK:    tail call void asm sideeffect "", "~{frm}"()
void test_frm(void) {
  asm volatile ("" :::"frm");
}

// CHECK-LABEL: define {{.*}} void @test_vtype
// CHECK:    tail call void asm sideeffect "", "~{vtype}"()
void test_vtype(void) {
  asm volatile ("" :::"vtype");
}

// CHECK-LABEL: define {{.*}} void @test_vl
// CHECK:    tail call void asm sideeffect "", "~{vl}"()
void test_vl(void) {
  asm volatile ("" :::"vl");
}

// CHECK-LABEL: define {{.*}} void @test_vxsat
// CHECK:    tail call void asm sideeffect "", "~{vxsat}"()
void test_vxsat(void) {
  asm volatile ("" :::"vxsat");
}

// CHECK-LABEL: define {{.*}} void @test_vxrm
// CHECK:    tail call void asm sideeffect "", "~{vxrm}"()
void test_vxrm(void) {
  asm volatile ("" :::"vxrm");
}
