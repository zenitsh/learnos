#include "typedef.h"

#define SIE_EXTERNAL_EN (1L<<9)
#define SIE_TIMER_EN (1L<<5)
#define SIE_SOFTWARE_EN (1L<<1)

#define SSTATUS_PREVIOS (1L<<8)
#define SSTATUS_PREVIOS_EN (1L<<5)
#define SSTATUS_USER_PREVIOS_EN (1L<<4)
#define SSTATUS_INT_EN (1L<<1)
#define SSTATUS_USER_INT_EN (1L<<0)

u64 set_sie_on(u64 x);
u64 set_sie_off(u64 x);

u64 set_sip_on(u64 x);
u64 set_sip_off(u64 x);

u64 set_sstatus_on(u64 x);
u64 set_sstatus_off(u64 x);

void int_en();

void timer_en();
