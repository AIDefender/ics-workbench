#ifndef __UTILS_H__
#define __UTILS_H__
#include "common.h"

// ----------------------debug--------------------------
void print_bi(uint32_t num, int width);
void show_cache();
// ----------------------helper-------------------------
uint32_t* cache2mem(uintptr_t mem_addr, uint8_t* cache_line);
uint32_t* query_cache_addr(uintptr_t addr);
cchent* query_cache_entry(uintptr_t addr);


// ----------------------read---------------------------
cchent* substi_cache(cchent* grp_base,uint32_t idx_of_grp);
void cpy_cache(uintptr_t mem_addr, cchent* cache_entry);
void load_cache(uintptr_t addr);


// ---------------------write---------------------------
void dump_cache(uint32_t*,cchent*, uint32_t, uint32_t);

#endif