#include "multimod.h"
#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <stdlib.h>
// static int64_t gen_rand_64();
static int64_t compute_res(int64_t,int64_t,int64_t);
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  // clock_t start=clock(), diff;
  // int i;
  // for(i=0;i<100000;i++)
  // { 
  //   a = gen_rand_64();
  //   b = gen_rand_64();
  //   m = gen_rand_64();
  //   printf("%ld %ld %ld %ld\n",a,b,m,compute_res(a,b,m));
  // } 
  // diff = clock()-start;
  // int msec = diff * 1000 / CLOCKS_PER_SEC;
  // printf("time=%dms\n",msec);

  return compute_res(a,b,m);
}
// int64_t gen_rand_64()
// {
//   return rand();
// }
int64_t compute_res(int64_t a, int64_t b, int64_t m)
{
  uint32_t f = 0xffffffff;
  uint32_t a2 = a&f;
  uint32_t b2 = b&f;
  int32_t a1 = a>>32;
  int32_t b1 = b>>32;

  int32_t a1_m = a1 % m;
  int32_t b1_m = b1 % m;
  int32_t a2_m = a2 % m;
  int32_t b2_m = b2 % m;

  printf("%d %d %d %d\n",a1,a2,b1,b2);
  printf("%d %d %d %d\n",a1_m,a2_m,b1_m,b2_m);

  printf("%ld\n",a2_m*b2_m%m);

  int64_t m_2 =(int64_t) pow(2,32) % m;


  int64_t res = ((((m_2 * m_2)%m) * a1_m)%m * b1_m)% m  + m_2*((a1_m*b2_m)%m+(a2_m*b1_m)%m)%m + a2_m*b2_m%m;
  
  return res;

}

