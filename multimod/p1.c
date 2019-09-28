#include "multimod.h"
#include <stdio.h>


int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  uint32_t f = 0xffffffff;
  uint32_t a2 = a&f;
  uint32_t b2 = b&f;
  int32_t a1 = a>>32 &f;
  int32_t b1 = b>>32 &f;
  printf("%d %d %u %u\n",a1,b1,a2,b2);
  return 0;
}

