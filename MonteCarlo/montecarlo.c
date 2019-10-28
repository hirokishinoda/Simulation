#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_LOOP 1000000

int main(void){
  double x,y,d;
  int count_in_circle = 0;
  int i;

  srand((unsigned) time(NULL));
  // init_genrand(seed);

  i = 0;
  while(i < MAX_LOOP){
    // x = genrand_real1();
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    d = x*x + y*y;
    if(d <= 1) count_in_circle++;
    i++;
  }

  printf("pi : %lf\n",(double)(4*count_in_circle) / MAX_LOOP);

  return 0;
}
