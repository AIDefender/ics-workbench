#include <stdint.h>
#include "util.h"
static int64_t compute_res(int64_t,int64_t,int64_t);

GEN_FUNC(3)

int64_t compute_res(int64_t a, int64_t b, int64_t m) {
  int64_t t = (a * b - (int64_t)((double)a * b / m) * m) % m;
  return t < 0 ? t + m : t;
}
