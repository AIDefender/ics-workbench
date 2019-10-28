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
  int x=0;
  asm ("xor %%rax, %%rax\n"
       "xor %%edx, %%edx;"
       : 
       : 
       : "%rax","%edx");
  asm ("dest2:shr $0x1, %[in] \n"
       "mov %[in], %%rdi\n"
       "and $0x1, %[in]\n"
       "test %[in], %[in]\n"
       "je dest1\n"
       "inc %%rax\n"
       "dest1:mov %%rdi,%[in]\n"
       "inc %%edx\n"
       "cmp $0x3f,%%edx\n"
       "jne dest2\n"
       "mov %%rax, %[out]\n"
       : [out] "+m"(x)
       : [in] "b" (n)
       : "%rax","%rdx","%rcx","%rbx","%rdi","cc","memory");
  
  return x;
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
