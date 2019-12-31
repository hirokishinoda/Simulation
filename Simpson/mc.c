#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100000
#define MIN_Y -11

double f(double x){
  return pow(x,4.0) - 8 * pow(x,3.0) + 18 * pow(x,2.0) - 11;
}

int main(void){
  double x,y;
  int x_1 = -1;
  int x_2 = 4;
  int i;
  int count = 0;

  srand((unsigned) time(NULL));

  for(i = 0;i < N;i++){
    // ランダムにxを決定
    x = x_1 + rand() % (x_2 - x_1) + (double)rand() / RAND_MAX;
    // ランダムにyを決定
    y = MIN_Y + rand() % ((int)f(x_2) - MIN_Y) + (double)rand() / RAND_MAX;
    // yがf(x)より小さかったらカウント（関数の面積内をカウント）
    if (f(x) < 0){
      if (y > f(x) && y < 0) count--;
    }else{
      if (y < f(x) && y >= 0) count++;
    }
    //printf("x=%lf,y=%lf,f(x)=%lf,count=%d\n",x,y,f(x),count);
  }
  printf("S = %lf\n",(double)(x_2 - x_1) * (f(x_2) - MIN_Y) * count / N);

  return 0;
}
