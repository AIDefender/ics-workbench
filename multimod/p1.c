#include "multimod.h"
#include <stdio.h>


int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  int64_t res=0;
  if (m==1) return 0;
  if (m==2) return (a&1)&&(b&1);
    
  while (a > 0) 
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

