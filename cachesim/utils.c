#include "utils.h"

extern cchent* cache;
void mem_read(uintptr_t block_num, uint8_t *buf);
void mem_write(uintptr_t block_num, const uint8_t *buf);
void print_bi(uint32_t num, int width)
{
  int i;
  for(i = width-1; i >= 0; i--)
  {
    if ((num / exp2(i))&1 )
    {
      printf("1");
    }
    else 
    {
      printf("0");
    }
    num %= exp2(i);
  }
  printf("\n");
}
void show_cache()
{
  int i = 0;
  for (;i < row_cache; i++)
  {
    printf("line %d:   ",i);
    int j = 0;
    for(;j<BLOCK_SIZE;j++)
    {
      printf("%x",cache[i].data[j]);
    }
    printf("\n");
  }
}

uint32_t* cache2mem(uintptr_t mem_addr, uint8_t* cache_line)
{
  uint32_t* ret = (uint32_t*)(cache_line + block_addr(mem_addr));
  // printf("ret:%x\n",*ret);  
  return ret;
}
uint32_t* query_cache_addr(uintptr_t addr)
{
  /*
    query cache with mem address "addr".
    If success, return pointer pointing to desired cache data addr
    If fail, return Null.
  */
  cchent* grp_queried_base = grp_addr(mem_index(addr));
  int i;
  for(i = 0; i < exp2(asso_width); i++)
  {
    if ((grp_queried_base[i].valid_bit == VALID) && (grp_queried_base[i].tag == mem_tag(addr)) )
    {
      return cache2mem(addr,grp_queried_base[i].data);
    }
  }
  return NULL;
}
cchent* query_cache_entry(uintptr_t addr)
{
	cchent* grp_queried_base = grp_addr(mem_index(addr));
  int i;
  for(i = 0; i < exp2(asso_width); i++)
  {
    if ((grp_queried_base[i].valid_bit == VALID) && (grp_queried_base[i].tag == mem_tag(addr)) )
    {
      return grp_queried_base+i;
    }
  }
  return NULL;
}

void cpy_cache(uintptr_t mem_addr, cchent* cache_entry)
{
  assert(cache_entry->valid_bit == INVALID);
  mem_read(block_num(mem_addr),cache_entry->data);
  cache_entry->valid_bit = VALID;
  cache_entry->tag = mem_tag(mem_addr);
}
cchent* substi_cache(cchent* grp_base, uint32_t idx_of_grp)
{
	uint32_t substi_index = rand() % exp2(asso_width);
	cchent* row_substitued = grp_base + substi_index;
	if (row_substitued->write_bit == DIRTY)
	{
		mem_write((row_substitued->tag << index_width) | idx_of_grp, row_substitued->data);
		row_substitued->write_bit = CLEAN;
	}
	row_substitued->valid_bit = INVALID;
	
}
void load_cache(uintptr_t addr)
{
  cchent* grp_queried_base = grp_addr(mem_index(addr));
  int i;
  for (i = 0; i < exp2(asso_width); i++)
  {
    if (grp_queried_base[i].valid_bit == INVALID)
    {
      cpy_cache(addr,grp_queried_base+i);
      return;
    }
  }
  cchent* substi_cache_addr = substi_cache(grp_queried_base,mem_index(addr));
  cpy_cache(addr,substi_cache_addr);
}
void dump_cache(uint32_t* cache_addr, cchent* cache_entry, uint32_t data, uint32_t wmask)
{
	assert(cache_addr >= (uint32_t*)cache_entry->data);
  *cache_addr = (*cache_addr & ~wmask) | (data & wmask);
	cache_entry->write_bit = DIRTY;
}
