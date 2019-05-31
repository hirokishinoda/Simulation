#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return 3 * ;
}

double gradient_f(double x){
  return 2 * x;
}

void newton(double a_0){
  double x_k = 0;
  double x_k1 = a_0;

  while(fabs(x_k - x_k1) > DBL_EPSILON){
    x_k = x_k1;
    x_k1 -= f(x_k) / gradient_f(x_k);
  }

  printf("%.10lf\n",x_k1);
}

int main(void){

  newton(2.0);

  return 0;
}
