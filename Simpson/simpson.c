#include <stdio.h>
#include <math.h>
#define N 10000

// 使用する関数
double f(double x){
  return pow(x,4.0) - 8 * pow(x,3.0) + 18 * pow(x,2.0) - 11;
}

int main(void){
  double range_x1 = -1.0;
  double range_x2 = 4.0;
  double x,h;
  double total,S;
  int i;

  // 間隔の計算
  h = (range_x2 - range_x1) / (double)N;
  // 積分計算
  // １つ目を先に計算
  total = f(range_x1);
  // ２つ目の地点以降を計算
  for(i = 1;i <= N;i++){
    // xを決定
    x = range_x1 + h*i;
    // xが偶数地点だったら
    if(i % 2 == 0) total += 2 * f(x);
    else total += 4 * f(x);
  }
  // 面積計算
  S = h * total / 3.0;

  printf("S = %lf\n",S);

  return 0;
}
