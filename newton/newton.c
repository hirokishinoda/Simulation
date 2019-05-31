#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

double f(double x){
  //return x * x - 2;
  return 3.0 * atan(x - 1.0) + x / 4.0;
}

double gradient_f(double x){
  //return 2*x;
  return 3.0 / (1.0 + pow(x-1.0,2.0)) + 0.25;
}

void newton(double a_0){
  double x_k = 0;
  double x_k1 = a_0;

  while(fabs(x_k - x_k1) > DBL_EPSILON){
    x_k = x_k1;
    x_k1 -= f(x_k) / gradient_f(x_k);
    printf("%.10lf %.10lf\n",x_k1,f(x_k1));
  }
}

int main(void){

  //newton(2.0);
  newton(2.5);
  //newton(3.0);

  return 0;
}
