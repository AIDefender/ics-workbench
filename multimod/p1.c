#include "multimod.h"
#include <stdio.h>
#define ll int64_t
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {

  int64_t a1=a&18446744069414584320u >> 32;
  a1 = (int) a1;
  int64_t b1=b&18446744069414584320u >> 32;
  b1 = (int) b1;
  int32_t a2=(int) a;
  int32_t b2=(int) b;
  int32_t m=(int) m;

  return a2*b2 % m;
}

int32_t int_mod(int32_t a, int32_t b, int32_t m){

  int res=0;
  
  while (b > 0) 
  { 
      // If b is odd, add 'a' to result 
      if (b % 2 == 1) 
          res = (res + a) % m; 

      // Multiply 'a' with 2 
      a = (a * 2) % m; 

      // Divide b by 2 
      b /= 2; 
  } 

  // Return result 
  return res % m;

}
