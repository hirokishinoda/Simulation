#include <stdio.h>
#include <math.h>

int main(void){
  double a = 2;
  double b = -95;
  double c = 0.1;
  double x_1 = 0.0;
  double x_2 = 0.0;

  if (b >= 0){
    x_2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    x_1 = c / (a*x_2);
  }else{
    x_1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    x_2 = c / (a*x_1);
  }

  printf("%.40f\n%.40f\n",x_1,x_2);

  return 0;
}
