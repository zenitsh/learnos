#include "sbicall.h"

void main(){
  char str[]="hello, world!";
  char * p_str = str;
  while(*p_str)
    putchar(*p_str++);
  while(1);
}
