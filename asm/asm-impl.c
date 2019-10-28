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
       "movl $0x0, -0x4(%%rbp)\n"
       "dest2:shr $0x1, %[in] \n"
       "mov %[in], -0x18(%%rbp)\n"
       "and $0x1, %[in]\n"
       "test %[in], %[in]\n"
       "je dest1\n"
       "inc %%rax\n"
       "dest1:mov -0x18(%%rbp),%[in]\n"
       "inc -0x4(%%rbp)\n"
       "cmp $0x3f,-0x4(%%rbp)\n"
       "jne dest2\n"
       "mov %%rax, %[out]\n"
       : [out] "+g"(x)
       : [in] "r" (n)
       : "%rax");
  
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
