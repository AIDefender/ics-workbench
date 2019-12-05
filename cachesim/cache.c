#include "common.h"
#include <inttypes.h>

static cchent* cache;


void mem_read(uintptr_t block_num, uint8_t *buf);
void mem_write(uintptr_t block_num, const uint8_t *buf);

static uint64_t cycle_cnt = 0;

void query_cache_hit(uintptr_t addr, bool* success)
{

}

uint32_t query_cache_addr(uintptr_t addr)
{

}

void load_cache(uintptr_t addr)
{
  
}

void cycle_increase(int n) { cycle_cnt += n; }

// TODO: implement the following functions

uint32_t cache_read(uintptr_t addr) {
  bool success = false;
  query_cache_hit(addr,&success);
  if (success)
  {
    return query_cache_addr(addr);
  }
  else 
  {
    load_cache(addr);
    query_cache_hit(addr,&success);
    assert(success);
    return query_cache_addr(addr);
  }
  
  return 0;
}

void cache_write(uintptr_t addr, uint32_t data, uint32_t wmask) {

}

void init_cache(int total_size_width, int associativity_width) {

  /*
  Can not be initialized with variable width!

  typedef struct cache
  {
    uint32_t valid_bit : 1;
    uint32_t write_bit : 1;
    uint32_t tag : MEM_WIDTH + associativity_width - total_size_width;
    uint32_t index : total_size_width - BLOCK_WIDTH - associativity_width;
    uint32_t int_addr : BLOCK_WIDTH;
  } cache_entry;
   
  */
  assert(associativity_width <= total_size_width);
  tag_with = 20 + associativity_width - total_size_width;
  uint32_t row_cache = exp2(total_size_width-BLOCK_WIDTH);
  cache = (cchent*)malloc(sizeof(cchent)*row_cache);
  int i = 0;
  for(i = 0; i < row_cache; i++)
  {
    cache[row_cache].valid_bit = 0;
  }
}

void display_statistic(void) {
}
