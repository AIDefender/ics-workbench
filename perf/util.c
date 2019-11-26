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