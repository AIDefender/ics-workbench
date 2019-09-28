#include "multimod.h"
#include <stdio.h>
#include <math.h>

int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  uint32_t f = 0xffffffff;
  uint32_t a2 = a&f;
  uint32_t b2 = b&f;
  int32_t a1 = a>>32;
  int32_t b1 = b>>32;

  int32_t a1_m = a1 % m;
  int32_t b1_m = b1 % m;
  int32_t a2_m = a2 % m;
  int32_t b2_m = b2 % m;

  int64_t m_2 =(int64_t) pow(2,32) % m;

  printf("%d %d %d %d %ld \n",a1_m,b1_m,a2_m,b2_m,m_2);

  int64_t res = (m_2 * m_2 * a1_m * b1_m)% m  + m_2*(a1_m*b2_m+a2_m*b1_m)%m + a2_m*b2_m%m;
  
  return res;
}

