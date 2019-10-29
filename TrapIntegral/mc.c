#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOOP 10000

double f(double x){
  return 2*x*x + 3*x;
}

int main(void){
  double x,y;
  int x_1 = 1;
  int x_2 = 2;
  int i;
  int count;

  srand((unsigned) time(NULL));

  for(i = 0;i < MAX_LOOP;i++){
    x = rand() % (x_2 - x_1) + x_1 + (double)rand() / RAND_MAX;
    y = rand() % (int)f(x_2) + (double)rand() / RAND_MAX;

    if (y < f(x)) count++;

    //printf("x=%lf,y=%lf,f(x)=%lf\n",x,y,f(x));
  }

  printf("S = %lf\n",(int)f(x_2)*(double)count/MAX_LOOP);

  return 0;
}
