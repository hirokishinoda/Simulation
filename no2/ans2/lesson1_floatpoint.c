/*
 * IEEE754(単精度)の浮動小数点表現を実際に見てみる
 */

#include <stdio.h>

#define BIT 32

int main(void)
{
  int i, j, bit[BIT];
  float x;

  printf("num = ");
  scanf("%f", &x);
  printf("\n");

/* float型とint型は同じ32ビットなので，int型にキャスト．
 * 同じビット列でint型になる．これをビットシフトして中身を確認する．
 */
  j = *(int *)&x; 
  printf("j=%d\n", j);
  
  /* ビット列を1つずつ確認 */
  for (i=0; i<BIT; i++) {
    bit[i] = (j>>i) & 1;
  }

  /* 4bit区切りで表示 */
  printf("%f -> ", x);
  for (i=BIT-1; i>=0; i--) {
    printf("%d", bit[i]);
    if(i%4==0) {
      printf(" ");
    }
  }
  printf("\n\n");

  /* IEEE754がわかりやすくなるように区切って表示 */
  printf("%f -> ", x);
  for (i=BIT-1; i>=0; i--) {
    printf("%d", bit[i]);
    if(i==BIT-1 || i==BIT-8-1) {
      printf(" ");
    }
  }
  printf("\n");
  

  return 0;
}
