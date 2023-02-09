#include "sbicall.h"

i64 sbi_call(u64 which, u64 arg0, u64 arg1, u64 arg2){
  register u64 a0 asm("a0") = arg0;
  register u64 a1 asm("a1") = arg1;
  register u64 a2 asm("a2") = arg2;
  register u64 a7 asm("a7") = which;
  asm volatile("ecall":"+r"(a0):"r"(a1),"r"(a2),"r"(a7):"memory");
  return (i64)a0;
}

void putchar(char c){
  sbi_call(SBI_CONSOLE_PUTCHAR, (unsigned char)c, 0, 0);
}

void set_timer(u64 a0){
  sbi_call(SBI_SET_TIMER, a0, 0, 0);
}
