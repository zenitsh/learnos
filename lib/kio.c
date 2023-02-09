#include "kio.h"
#include "sbicall.h"

void put(const char * str){
  char * s = (char*)str;
  while(*s)
    putchar(*s);
}
