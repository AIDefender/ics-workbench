#include "multimod.h"
#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <stdlib.h>
int64_t gen_rand_64();
int64_t compute_res(int64_t,int64_t,int64_t);
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  time_t start, end;
  time(&start);
  int i;
  for(i=0;i<10000;i++)
  { 
    a = gen_rand_64();
    b = gen_rand_64();
    m = gen_rand_64();
    printf("%ld\n",compute_res(a,b,m));
  } 
  time(&end);
  printf("time=%f\n",difftime(end,start)); 
  return 0;
}
int64_t gen_rand_64()
{
  return (rand()<<31)+rand();
}
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

  int64_t m_2 =(int64_t) pow(2,32) % m;


  int64_t res = (m_2 * m_2 * a1_m * b1_m)% m  + m_2*(a1_m*b2_m+a2_m*b1_m)%m + a2_m*b2_m%m;
  
  return res;

}

