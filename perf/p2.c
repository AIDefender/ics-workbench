#include <stdint.h>
#include "util.h"

static int64_t compute_res(int64_t,int64_t,int64_t);

GEN_FUNC(2)


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
