#include <stdint.h>
#include <unistd.h>

// TODO: set correct array length
typedef uintptr_t asm_jmp_buf[8]; //*里面都是指针类型

int64_t asm_add(int64_t a, int64_t b);
int asm_popcnt(uint64_t x);
void *asm_memcpy(void *dest, const void *src, size_t n);
int asm_setjmp(asm_jmp_buf env);
void asm_longjmp(asm_jmp_buf env, int val);
