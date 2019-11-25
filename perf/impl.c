#include "perf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void dummy() {
}

void print_hello() {
  printf("hello\n");
}

void print_error() {
  printf("invalid subject!\n");
  exit(1);
}

void simple_loop() {
  for (volatile int i = 0; i < 1000000; i++) ;
    // printf("haha");
}

int64_t gen_rand_64()
{
  //1
  int i = 0;
  int64_t res=rand()%2;
  for(;i<62;i++)
  {
    res <<= 1;
    res+=rand()%2;
  }
  return res;
}
int64_t compute_res_1(int64_t a, int64_t b, int64_t m);

void multimod_p1() {

  int64_t a = gen_rand_64();
  int64_t b = gen_rand_64();
  int64_t m = gen_rand_64();

  volatile int64_t res = compute_res_1(a,b,m);
}

int64_t compute_res_1(int64_t a, int64_t b, int64_t m)
{
  int *a_bits = gen_bits(a);
  int *b_bits = gen_bits(b);
  int i = 0;
  int j = 0;
  uint64_t res=0;
  for(i=0;i<63;i++)
  {
    for(j=0;j<63;j++)
    {

      if (b_bits[j]==0)
      {
        continue;
      }
      int k;
      int64_t am=a_bits[i];
      for(k=0;k<i+j;k++)
      {
        if (am>m)
        {
          am = (am % m) << 1; 
        }  
        else 
        {
          if (am>(m>>1))
          {
            am=(am-m+am)%m;
          }
          else 
          {
            am<<=1;
          }
        }
      }
      res = (res%m+am%m)%m;
    }
  }
  
  return (int64_t)res;
}