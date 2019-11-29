#ifndef __UTIL_H__
#define __UTIL_H__
#include <stdint.h>
#include <stdio.h>

// #define WRITE_FILE

#ifdef WRITE_FILE
#define GEN_FUNC(x) \
    void multimod_p##x(void) { \
        int a_num_1 = 0; \
        int a_hi_1 = 0; \
        int b_num_1 = 0; \
        int b_hi_1 = 0; \
        int m_num_1 = 0; \
        int m_hi_1 = 0; \
        int64_t a = gen_rand_64(&a_num_1,&a_hi_1); \
        int64_t b = gen_rand_64(&b_num_1,&b_hi_1); \
        int64_t m = gen_rand_64(&m_num_1,&m_hi_1); \
        static volatile int64_t res __attribute__((used)) = 0; \
        res = compute_res(a,b,m); \
        FILE* file; \
        file = fopen("num_1","a"); \
        fprintf(file,"%d,%d,%d\n",a_num_1,b_num_1,m_num_1); \
        fclose(file); \
        file = fopen("hi_1","a"); \
        fprintf(file,"%d,%d,%d\n",a_hi_1,b_hi_1,m_hi_1); \
        fclose(file); \
    }

int64_t gen_rand_64(int*,int*);
#else
#define GEN_FUNC(x) \
    void multimod_p##x(void) { \
        int64_t a = gen_rand_64(); \
        int64_t b = gen_rand_64(); \
        int64_t m = gen_rand_64(); \
        static volatile int64_t res __attribute__((used)) = 0; \
        res = compute_res(a,b,m); \
    }
int64_t gen_rand_64();
#endif
#endif