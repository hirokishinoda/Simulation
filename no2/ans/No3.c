/*
 * No3
 *
 * 情報落ち
 *
 * 123,456,789(1億2345万6789)に0.000000001を10回足しても
 * 123456789.00000001にならない
 *
 * (1) 1桁大きい0.00000001であれば，演算結果はどうなるか?
 * (2) 0.1であれば，演算結果はどうなるか?
 */

#include <stdio.h>

#define ITERATION 10

int main(void)
{
  int i;
  int sum_i;
  double sum_d;

  sum_i = 123456789;
  sum_d = 123456789;
  for (i=0; i<ITERATION; i++) {
    //printf("%d\n", sum_i);
    printf("%d %d %f\n", i, sum_i, sum_d);
    sum_i += 0.00000001;
    sum_d += 0.00000001;
  }

  return 0;
}
