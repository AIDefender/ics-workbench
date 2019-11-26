#include <stdio.h>
#include <math.h> 
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "util.h"
static int64_t compute_res(int64_t,int64_t,int64_t);

void multimod_p3(void) {

  int64_t a = gen_rand_64();
  int64_t b = gen_rand_64();
  int64_t m = gen_rand_64();

  static volatile int64_t res __attribute__((used)) = 0;
  res = compute_res(a,b,m);

}


int64_t compute_res(int64_t a, int64_t b, int64_t m) {
  int64_t t = (a * b - (int64_t)((double)a * b / m) * m) % m;
  return t < 0 ? t + m : t;
}
