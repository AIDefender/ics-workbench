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
  asm ("1:shr $0x1, %0 \n"
       "mov %0, %%rdi\n"
       "and $0x1, %0\n"
       "test %0, %0\n"
       "je 2b\n"
       "inc %%eax\n"
       "2:mov %%rdi,%0\n"
       "inc %%edx\n"
       "cmp $0x3f,%%edx\n"
       "jne 1b\n"
       : 
       : "r" (n)
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
