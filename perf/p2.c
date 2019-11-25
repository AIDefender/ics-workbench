#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

static int64_t gen_rand_64();
static int64_t compute_res(int64_t,int64_t,int64_t);
void multimod_p2(void) {

  int64_t a = gen_rand_64();
  int64_t b = gen_rand_64();
  int64_t m = gen_rand_64();

  static volatile int64_t res __attribute__((used)) = 0;
  res = compute_res(a,b,m);

}
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
