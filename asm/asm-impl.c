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
       "dest2:mov %[in], -0x18(%%rbp)\n"
       "and $0x1, %[in]\n"
       "test %[in], %[in]\n"
       "je dest1\n"
       "inc %%rax\n"
       "dest1:mov -0x18(%%rbp),%[in]\n"
       "shr $0x1, %[in] \n"
       "incl -0x4(%%rbp)\n"
       "cmp $0x3f,-0x4(%%rbp)\n"
       "jle dest2\n"
       "mov %%rax, -0x18(%%rbp)\n"
       "mov -0x18(%%rbp), %[out]\n"
       : [out] "+g"(x)
       : [in] "r" (n)
       : "%rax","cc","memory");
  
  return x;
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  void* pos=NULL;
  asm ("mov %[dest], %%rax\n"
       "mov %%rax, -0x18(%%rbp)\n" /*传递dest参数*/
       "mov %[src], %%rax\n"
       "mov %%rax, -0x20(%%rbp)\n"
       "mov %[n], %%rax\n"
       "mov %%rax, -0x28(%%rbp)\n"
       "mov -0x18(%%rbp), %%rax\n"
       "mov %%rax, %[pos]\n" /*传递pos参数*/
       "movl $0x0, -0xc(%%rbp)\n" /*loop variable*/
       "jmp start\n"
       "loop: mov -0x20(%%rbp),%%rax\n"
       "movzbl (%%rax),%%edx\n"
       "mov -0x18(%%rbp),%%rax\n"
       "mov %%dl, (%%rax)\n"
       "addq $0x1, -0x18(%%rbp)\n"
       "addq $0x1, -0x20(%%rbp)\n"
       "addq $0x1, -0xc(%%rbp)\n"
       "start: mov -0xc(%%rbp),%%rax\n"
       "cltq\n"
       "cmp %%rax, -0x28(%rbp)\n"
       "ja loop\n"
       : [pos] "+g"(pos)
       : [dest] "m"(dest), [src] "m"(src), [n] "m"(n)
       : "%rax", "%edx", "cc", "memory");
  return pos;
}

int asm_setjmp(asm_jmp_buf env) {
  // TODO: implement
  return 0;
}

void asm_longjmp(asm_jmp_buf env, int val) {
  // TODO: implement
}
