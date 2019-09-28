#include "multimod.h"
#include <stdio.h>
#define ll int64_t

int64_t int_mod(int64_t a, int64_t b, int64_t m);

int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {

  // int64_t f = 0xffffffff;

  // int a1=a&18446744069414584320u >> 32;
  // int b1=b&18446744069414584320u >> 32;
  // printf("%d %d\n",a1,b1);
  // int32_t a2=(int) a;
  // int32_t b2=(int) b;

  return int_mod(a,b,m);
}

int64_t int_mod(int64_t a, int64_t b, int64_t m){

  int64_t res=0;
  
  while (a > 0) 
  { 
      // If a is odd, add 'a' to result 
      if (a & 1) 
          res = res % m + b % m; 

      // Multiply 'b' with 2 
      b = (b % m) * (2 % m); 

      // Divide a ay 2 
      a >>= 1; 
  } 

  // Return result 
  return res % m;

}
