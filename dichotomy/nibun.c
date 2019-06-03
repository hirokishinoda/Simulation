#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

double f(double x){
  return x*x - 2;
}

void nibun(double a_0,double b_0){
  int k = 0;
  double a_k = a_0;
  double b_k = b_0;
  double c ;

  for (k = 0;fabs(a_k - b_k) > DBL_EPSILON;k++){
    c = (a_k + b_k)/2;

    if (f(c) * f(a_k) <= 0){
      a_k = a_k;
      b_k = c;
    }else{
      a_k = c;
      b_k = b_k;
    }
  }

  printf("%.10lf\n",c);
}

void hasaami(double a_0,double b_0){
  int k = 0;
  double a_k = a_0;
  double b_k = b_0;
  double w_k;
  double c ;

  for (k = 0;fabs(a_k - b_k) > DBL_EPSILON;k++){
    w_k = (f(b_k)*a_k - f(a_k)*b_k) / (f(b_k) - f(a_k));

    if(f(w_k) * f(a_k) <= 0){
      a_k = a_k;
      b_k = w_k;
    }else{
      a_k = w_k;
      b_k = b_k;
    }
  }

  printf("%.10lf\n",w_k);
}

int main(void){

  nibun(0.0, 2.0);

  hasaami(0.0,2.0);

  return 0;
}
