#include "asm.h"
#include <string.h>

int64_t asm_add(int64_t a, int64_t b) {
  // TODO: implement
  asm ("add %1, %0;"
       : "+r" (a)
       : "r" (b)
      );
  return a;
}

int asm_popcnt(uint64_t n) {
  // TODO: implement
  asm ("xor %%rax, %%rax\n"
       "xor %%edx, %%edx;"
       : 
       : 
       : "%rax","%edx");
  asm ("shr %0, $0x1\n"
       "inc %%edx\n"
       "cmp $0x3F,%%edx\n"
       "jne "
       : "=r" (n)
       : "0" (n)
       : "%rax","%edx");
  
  return 0;
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  // TODO: implement
  return NULL;
}

int asm_setjmp(asm_jmp_buf env) {
  // TODO: implement
  return 0;
}

void asm_longjmp(asm_jmp_buf env, int val) {
  // TODO: implement
}
