#include <stdio.h>

#define NUM 1000000

int main(void){
  double num = 0.0;
  int i;

  for(i = 0;i < NUM;i++){
    num += 0.1;
  }

  printf("%lf\n",num);

  return 0;
}
