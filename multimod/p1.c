#include "multimod.h"
#include <stdio.h>
#define ll int64_t
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {

  (int) a,b,m;
  
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
