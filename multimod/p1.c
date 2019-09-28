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
  
  while (b > 0) 
  { 
      // If b is odd, add 'a' to result 
      if (b % 2 == 1) 
          res = (res + a) % m; 

      // Multiply 'a' with 2 
      a = (a % m) * (2 % m); 

      // Divide b by 2 
      b /= 2; 
  } 

  // Return result 
  return res % m;

}
