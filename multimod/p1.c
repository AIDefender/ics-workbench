#include "multimod.h"

int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  return ((a%m)*(b%m))%m;
}
