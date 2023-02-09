#include "int.h"

u64 set_sie_on(u64 x){
  u64 t;
  asm volatile("csrr %0, sie":"=r"(t)::);
  t = t|x;
  asm volatile("csrw sie, %0"::"r"(t):);
}

u64 set_sie_off(u64 x){
  u64 t;
  asm volatile("csrr %0, sie":"=r"(t)::);
  t = t&(~x);
  asm volatile("csrw sie, %0"::"r"(t):);
}

u64 set_sip_on(u64 x){
  u64 t;
  asm volatile("csrr %0, sip":"=r"(t)::);
  t = t|x;
  asm volatile("csrw sip, %0"::"r"(t):);
}

u64 set_sip_off(u64 x){
  u64 t;
  asm volatile("csrr %0, sip":"=r"(t)::);
  t = t&(~x);
  asm volatile("csrw sip, %0"::"r"(t):);
}

u64 set_sstatus_on(u64 x){
  u64 t;
  asm volatile("csrr %0, sstatus":"=r"(t)::);
  t = t|x;
  asm volatile("csrw sstatus, %0"::"r"(t):);
}

u64 set_sstatus_off(u64 x){
  u64 t;
  asm volatile("csrr %0, sstatus":"=r"(t)::);
  t = t&(~x);
  asm volatile("csrw sstatus, %0"::"r"(t):);
}

void int_en(){
  set_sstatus_on(SSTATUS_INT_EN);
}

void timer_en(){
  set_sie_on(SIE_TIMER_EN);
}
