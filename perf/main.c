#include "perf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>

#define DECL(fn) void fn();

PROGRAMS(DECL)

static void run(void (*func)(), int rounds);
static uint64_t gettime();
static void (*lookup(const char *fn))();

int main(int argc, char **argv) {
  // TODO: parse arguments: set @func and @rounds
  // printf("%d\n",argc);
  int rounds = 1;
  int i;
  char func_name[20];
  for(i=1;i<argc;i++)
  {
    // printf("%s\n",argv[i]);
    if (strcmp(argv[i],"-r")==0)
    {
      i++;
      rounds = atoi(argv[i]);
    }
    else 
    {
      strcpy(func_name,argv[i]);
    }
  }
  printf("%d\n%s\n",rounds,func_name);
  void (*func)() = lookup("dummy");


  run(func, rounds);
}

static uint64_t gettime() {
  // TODO: implement me!
  return time(NULL);
}

static void (*lookup(const char *fn))() {
  #define PAIR(fn) { #fn, fn },
  struct pair {
    const char *name;
    void *ptr;
  };
  struct pair lut[] = {
    PROGRAMS(PAIR)
  };

  for (int i = 0; i < LENGTH(lut); i++) {
    struct pair *p = &lut[i];
    if (strcmp(fn, p->name) == 0) return p->ptr;
  }
  return print_error;
}

static void run(void (*func)(), int rounds) {
  uint64_t *elapsed = malloc(sizeof(uint64_t) * rounds);
  if (!elapsed) {
    perror("elapsed");
    return;
  }

  for (int round = 0; round < rounds; round++) {
    uint64_t st = gettime();
    func();
    uint64_t ed = gettime();
    elapsed[round] = ed - st;
  }

  // TODO: display runtime statistics

  free(elapsed);
}
