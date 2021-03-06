#include "common.h"
#include <inttypes.h>
#include "utils.h"

cchent* cache;
static uint32_t miss_num;
static uint32_t hit_num;

static uint64_t cycle_cnt = 0;

void cycle_increase(int n) { cycle_cnt += n; }

// TODO: implement the following functions

uint32_t cache_read(uintptr_t addr) {
  // show_cache(); 
  uint32_t* data_addr = query_cache_addr(addr);
  
  if (data_addr)
  {
    // printf("hit!\n");
    hit_num++;
    return *data_addr;
  }
  else 
  {
    miss_num++;
    // printf("miss!\n");
    load_cache(addr);
    // show_cache();
    data_addr = query_cache_addr(addr);
    assert(data_addr);
    // printf("Read Once!\n");
    return *data_addr;
  }
  // printf("Read Once!\n");
  return 0;
}

void cache_write(uintptr_t addr, uint32_t data, uint32_t wmask) {

  uint32_t* dump_addr = query_cache_addr(addr);
  if (dump_addr)
  {
    cchent* cache_entry = query_cache_entry(addr);
    dump_cache(dump_addr,cache_entry,data,wmask);
  }
  else 
  {
    load_cache(addr);
    dump_addr = query_cache_addr(addr);
    assert(dump_addr);
    cchent* cache_entry = query_cache_entry(addr);
    dump_cache(dump_addr,cache_entry,data,wmask);
  }
  // printf("mem addr %lx written to cache.\n",addr);
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
  // printf("%d,%d\n",total_size_width,associativity_width);
  assert(associativity_width <= total_size_width);
  tag_width = MEM_WIDTH + associativity_width - total_size_width;
  index_width = total_size_width - BLOCK_WIDTH - associativity_width;
  assert((int)index_width>0);
  // asso_width = associativity_width;
  row_cache = exp2(total_size_width-BLOCK_WIDTH);
  cache = (cchent*)malloc(sizeof(cchent)*row_cache);
  int i = 0;
  for(i = 0; i < row_cache; i++)
  {
    cache[row_cache].valid_bit = INVALID;
  }
  miss_num = 0;
  hit_num = 0;
}

void display_statistic(void) {
  // printf("hit num:%u, miss num:%u, hit rate:%f%%\n.",hit_num,miss_num,(double)hit_num/(hit_num+miss_num));
  printf("%f\n",(double)hit_num/(hit_num+miss_num));
  // printf("%f\n",cycle_cnt/(double)(hit_num+miss_num));
}
