#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define exp2(x) (1 << (x))
#define mask_with_len(x) (exp2(x) - 1)

#define MEM_SIZE (1 << 25) // 1MB
#define BLOCK_WIDTH  6  // 64B
#define BLOCK_SIZE exp2(BLOCK_WIDTH)
#define MEM_WIDTH 25

typedef uint8_t bool;
#define true 1
#define false 0

// ---------Cache-------------

typedef struct 
{
    struct 
    {
        uint32_t valid_bit : 1;
        uint32_t write_bit : 1;
    };
    uint32_t tag;
    uint8_t data[BLOCK_SIZE];
} cchent;

uint32_t tag_width;
uint32_t asso_width;
uint32_t row_cache;
#define VALID 1 
#define INVALID 0 
#define DIRTY 1
#define CLEAN 0
#define grp_addr(index) (&(cache[index*exp2(asso_width)]))

// ----------Memory-----------
#define block_addr(addr) (addr & mask_with_len(BLOCK_WIDTH) & ~0x3)
#define mem_tag(addr) ((addr >> (MEM_WIDTH-tag_width)) & mask_with_len(tag_width))
#define mem_index(addr) ((addr >> BLOCK_WIDTH) & mask_with_len(MEM_WIDTH-tag_width-BLOCK_WIDTH))
#define block_num(addr) (addr >> (BLOCK_WIDTH))
// ---------------------------
void cycle_increase(int n);

#endif
