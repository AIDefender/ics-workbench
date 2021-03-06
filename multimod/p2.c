#include "multimod.h"
#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <assert.h>
#include <stdlib.h>

// Uncomment to enable timing 
// #define TIMING


#ifdef TIMING
static int64_t gen_rand_64();
#endif
static int64_t compute_res(int64_t,int64_t,int64_t);
int64_t multimod_p2(int64_t a, int64_t b, int64_t m) {
#ifdef TIMING
  clock_t start=clock(), diff;
  int i;
  for(i=0;i<10000;i++)
  { 
    a = gen_rand_64();
    assert(a>0);
    b = gen_rand_64();
    assert(b>0);
    m = gen_rand_64();
    assert(m>0);
    // assert(b%m>0);
    // printf("%ld %ld\n",a%m,b%m);
    printf("%ld %ld %ld ",a,b,m);
    printf("%ld\n",compute_res(a,b,m));
  } 
  diff = clock()-start;
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("time=%dms\n",msec); 
#endif
  return compute_res(a,b,m);
}
#ifdef TIMING
int64_t gen_rand_64()
{
  int i = 0;
  int64_t res=rand()%2;
  for(;i<62;i++)
  {
    res <<= 1;
    res+=rand()%2;
  }
  return res;
}
#endif
int64_t compute_res(int64_t a, int64_t b, int64_t m)
{
  uint64_t res=0;
  if (m==1) return 0;
  if (m==2) return (a&1)&&(b&1);
    
  while (a>0) 
  { 
      if (a & 1)
      {
        res = (res % m + b % m)%m; 
      } 
      if (b>m)
      {
        b = (b % m) << 1; 
      }  
      else 
      {
        if (b>(m>>1))
        {
          b=(b-m+b)%m;
        }
        else 
        {
          b<<=1;
        }
      }
      assert(b>=0);
      a >>= 1; 
      assert(res>=0);
  } 
  return (int64_t )res % m;

}
