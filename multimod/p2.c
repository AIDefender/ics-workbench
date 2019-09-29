#include "multimod.h"
#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <stdlib.h>
static int64_t gen_rand_64();
static int64_t compute_res(int64_t,int64_t,int64_t);
int64_t multimod_p2(int64_t a, int64_t b, int64_t m) {
  clock_t start=clock(), diff;
  int i;
  for(i=0;i<100000;i++)
  { 
    a = gen_rand_64();
    b = gen_rand_64();
    m = gen_rand_64();
    printf("%ld %ld %ld %ld\n",a,b,m,compute_res(a,b,m));
  } 
  diff = clock()-start;
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("time=%dms\n",msec); 
  return 0;
}
int64_t gen_rand_64()
{
  return rand();
}
int64_t compute_res(int64_t a, int64_t b, int64_t m)
{
  int64_t res=0;
  if (m==1) return 0;
  if (m==2) return (a&1)&&(b&1);
    
  while (a>0) 
  { 
      if (a & 1)
      {
        res = res % m + b % m; 
      } 
        
      b = (b % m) << 2; 
      a >>= 1; 
  } 
  return res % m;

}
