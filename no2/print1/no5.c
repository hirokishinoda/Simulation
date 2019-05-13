#include <stdio.h>

int main(void){
  
  double num_1 = 0.00000001234;
  double num_2 = 3141593;
  double c;

  c = num_1 + num_2;
  printf("c=%.11f\n",c);

  c = num_1 + num_1;
  printf("c=%.11f\n",c);

  return 0;
}
