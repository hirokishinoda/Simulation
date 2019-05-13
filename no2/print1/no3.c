#include <stdio.h>

#define NUM 10

int main(void){
  double num = 123456789.0;
  int i;
  
  for(i = 0;i < NUM;i++){
    num += 0.000000001;
    printf("%.30f\n",num);
  }

  for(i = 0;i < NUM;i++){
    num += 0.00000001;
    printf("%.30f\n",num);
  }

  return 0;
}
