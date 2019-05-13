#include <stdio.h>

int main(void){
  double num = 0.0;

  while(num < 1.0){
    num += 0.1;
    printf("%.32f\n",num);
  }

  return 0;
}
