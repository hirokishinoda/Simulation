#include <stdio.h>

#define N 1000
#define RANGE_X1 1.0
#define RANGE_X2 2.0

double f(double x){
  return 2*x*x + 3*x;
}

int main(void){
  int i;
  double x1,x2,h;
  double S;
  double range = (RANGE_X2 - RANGE_X1) / N;

  for(i = 0;i < N;i++){
    x1 = RANGE_X1 + i * range;
    x2 = RANGE_X1 + (i+1) * range;

    h = x2 - x1;
    S += h*(f(x1) + f(x2)) / 2;
  }

  printf("S = %lf\n",S);

  return 0;
}
