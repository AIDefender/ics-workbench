#include <stdlib.h>
#include "util.h"
#ifdef WRITE_FILE
int64_t gen_rand_64(int* num_1)
{
  int i = 0;
  *num_1 = 0;
  int64_t res=rand()%2;
  if (res) (*num_1)++;
  for(;i<62;i++)
  {
    res <<= 1;
    int num_gen = rand()%2;
    if (num_gen) (*num_1)++;
    res+=num_gen;
  }
  return res;
}
#else 
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
#endif