#include <stdio.h>
#include <time.h>

void f(double x){
  return 2 * x * x + 3 * x;
}

int main(void){
  double x,y;
  int x_1 = 1;
  int x_2 = 2;
  int count;

  srand((unsigned) time(NULL));

  for(i = 0;i < MAX_LOOP;i++){
    x = (double)rand() % x_2 + x_1;
    y = (double)rand() ;

    if (y < f(x)) count++;
  }

  return 0;
}
