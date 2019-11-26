#ifndef __UTIL_H__
#define __UTIL_H__

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