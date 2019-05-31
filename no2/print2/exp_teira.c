#include <stdio.h>
#include <math.h>

#define INDEX_MAX 50

float factorial(int x){
  int i;
  float result = 1;

  for(i = 1;i < x+1;i++){
    result *= i;
  }

  return result;
}

float exp_teylar(int x){
  float total = 0;
  int i;

  for(i = 0; i < INDEX_MAX;i++){
    total += powf(x,i) / factorial(i);
  }

  return total;
}

int main(void){

  printf("exp(-5):%.30f\n",exp_teylar(-5));

  return 0;
}
