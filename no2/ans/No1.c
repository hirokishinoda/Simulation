/*
 * No1
 *
 * 丸め語差
 *
 * 0.1を10回足して，ちょうど1.0になったときにループを抜けようとするが，抜けられない
 *
 * これは，よくやるミスの代表選手です．
 *
 */

#include <stdio.h>

int main(void)
{
  int i;
  double sum;

  sum = 0.0;
  for (i=0; i<15; i++) {
    printf("%2d %f %.32f\n", i, sum, sum);

    sum += 0.1;

    if (sum==1.0) {// ここを次のように修正する。if(sum>=1.0) {
      break;
    }
  }
  printf("\n");

  /*
  i = 0;
  sum = 0.0;
  while (sum<1.001) {
    printf("%2d %f %.32f\n", i, sum, sum);
    sum += 0.1;
    i++;
  }
  */

  return 0;
}
