#include "multimod.h"
#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <stdlib.h>
static int64_t gen_rand_64();
static uint64_t compute_res(int64_t,int64_t,int64_t);
static int* gen_bits(int64_t);
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  clock_t start=clock(), diff;
  int i;
  for(i=0;i<1;i++)
  { 
    a = gen_rand_64();
    b = gen_rand_64();
    m = gen_rand_64();
    printf("%ld %ld %ld %ld\n",a,b,m,compute_res(a,b,m));
  } 
  diff = clock()-start;
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("time=%dms\n",msec);

  return compute_res(a,b,m);
}
int64_t gen_rand_64()
{
  int i = 0;
  int64_t res=0;
  for(;i<62;i++)
  {
    res+=rand()%2;
    res <<= 1;
  }
  return res;
}
uint64_t compute_res(int64_t a, int64_t b, int64_t m)
{
  int *a_bits = gen_bits(a);
  int *b_bits = gen_bits(b);
  int i;
  for(i=0;i<63;i++)
  {
    printf("%d",a_bits[i]);
  }
  printf("\n");
  for(i=0;i<63;i++)
  {
    printf("%d",b_bits[i]);
  }
  printf("\n");
  return 0;
}

int* gen_bits(int64_t a){
  int *bits = (int*)malloc(63*sizeof(int));
  int i=0;
  while (a)
  {
    bits[i]=a%2;
    a >>= 1;
    i++;
  }
  return bits;
}

