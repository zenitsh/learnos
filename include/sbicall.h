#include "typedef.h"

#define SBI_SET_TIMER 0
#define SBI_CONSOLE_PUTCHAR 1
#define SBI_CONSOLE_GETCHAR 2
//...

i64 bi_call(u64 which, u64 a0, u64 a1, u64 a2);

void putchar(char c);
