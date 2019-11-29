#include <stdint.h>
#include <stdlib.h>
#include "util.h"


static int64_t compute_res(int64_t,int64_t,int64_t);
static int* gen_bits(int64_t);

GEN_FUNC(4)

int64_t compute_res(int64_t a, int64_t b, int64_t m)
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
      if (am==0)
      {
        continue;
      }
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

