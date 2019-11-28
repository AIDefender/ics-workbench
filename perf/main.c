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
static double gettime();
static void (*lookup(const char *fn))();

int main(int argc, char **argv) {
  // TODO: parse arguments: set @func and @rounds
  // printf("%d\n",argc);
  int rounds = 1;
  int i;
  char func_name[20];
  if (argc > 4)
  {
    printf("Too many arguments!\n");
    return -1;
  }
  for(i=1;i<argc;i++)
  {
    // printf("%s\n",argv[i]);
    if (strcmp(argv[i],"-r")==0)
    {
      i++;
      rounds = atoi(argv[i]);
      // printf("%d\n",rounds);
      if (rounds <= 0)
      {
        printf("Invalid rounds!\n");
        return -1;
      }
    }
    else 
    {
      strcpy(func_name,argv[i]);
    }
  }
  void (*func)() = lookup(func_name);


  run(func, rounds);
}

static double gettime() {
  clock_t t;
  t = clock();
  return ((double) t) / CLOCKS_PER_SEC;
  // TODO: implement me!
  // return time(NULL);
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
  double *elapsed = malloc(sizeof(uint64_t) * rounds);
  if (!elapsed) {
    perror("elapsed");
    return;
  }

  for (int round = 0; round < rounds; round++) {
    double st = gettime();
    func();
    double ed = gettime();
    elapsed[round] = ed - st;
  }
  FILE* file;
  file = fopen("res","w");

  int i = 0;
  for(;i<rounds;i++)
  {
    fprintf(file,"%f\n",elapsed[i]*1000);
  }
  fclose(file);
  // TODO: display runtime statistics

  system("python3 stat.py");
  system("rm res");
  system("rm num_1");
  system("rm hi_1");

  free(elapsed);
}
