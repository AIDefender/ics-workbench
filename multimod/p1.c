#include "multimod.h"
#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <stdlib.h>
#include <assert.h>
static int64_t gen_rand_64();
static int64_t compute_res(int64_t,int64_t,int64_t);
static int* gen_bits(int64_t);
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  clock_t start=clock(), diff;
  int i;
  for(i=0;i<1000;i++)
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
  //3
  int i = 0;
  int64_t res=rand()%2;
  for(;i<61;i++)
  {
    res <<= 1;
    res+=rand()%2;
  }
  return res;
}
int64_t compute_res(int64_t a, int64_t b, int64_t m)
{
  int *a_bits = gen_bits(a);
  printf("\n");
  int *b_bits = gen_bits(b);
  int i = 0;
  int j = 0;
  int64_t res=0;
  for(i=0;i<63;i++)
  {
    for(j=0;j<63;j++)
    {
      // int64_t am=a_bits[i]*((1l<<i) %m);
      // int64_t bm=b_bits[j]*((1l<<j) %m);
      // printf("%d %ld %ld %ld\n",j,am,bm,m);
      // ! bm可能超过32位,导致溢出
      // ! 说明这个方法根本上是错误的
      // ! 注意排查的方式.我:痛苦的debug;其实可以在代数层面多思考
      // !! 可以直接不停×2取模
      // res+=(am*bm)%m;
      // res=res%m;
      if (b_bits[j]==0)
      {
        continue;
      }
      int k;
      // int64_t am=(a_bits[i]<<i)%m;
      int64_t am=a_bits[i];
      for(k=0;k<i+j;k++)
      {
        am = (am << 1)%m;
      }

      // printf("am:%ld\n",am);//!这一步可能就有问题
      // if (j==0)
      // {
      //   res = (res+am)%m;
      //   continue; 
      // }
      // for(k=0;k<j;k++)
      // {
      //   am = (am << 1)%m;
      // }
      res = (res+am)%m;
    }
  }
  
  
  return res;
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
  // int ii=0;
  // for(;ii<63;ii++)
  // {
  //   printf("%d",bits[62-ii]);
  // }
  // printf("\n");
  return bits;
}

