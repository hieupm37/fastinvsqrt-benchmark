#include <stdio.h>

#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "gfmath.h"

int main(int argc, char **argv) {
  static const int num = 2000000;
  float val[num];
  int iternum = 1;
  float x;
  clock_t st, et;

  /* Init random generator */
  srand(time(0));

  for (int i = 0; i < num; ++i)
    val[i] = rand() + 100.0f;

  st =  clock();

  for (int i = 0; i < num; ++i) {
    x = val[i];
    x = FastInverseSqrt(x);
  }

  et = clock();

  printf("FIS: %lf\n", ((double)et - (double)st)/CLOCKS_PER_SEC);

  st = clock();

  for (int i = 0; i < num; ++i) {
    x = val[i];
    x = 1.0f / sqrtf(x);
  }

  et = clock();

  printf("sqrtf: %lf", ((double)et - (double)st)/CLOCKS_PER_SEC);

  return 0;
}
