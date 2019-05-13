/*
 * No4
 *
 * int型変数の扱える整数値の範囲
 *
 * int(32ビット) は -2147483648 から 2147483647 までの整数しか扱えない．
 *
 */

#include <stdio.h>

int main(void)
{
  /* int */
  int a;
  int b;
  int sum;

  a = 1840083528;
  b = 1343303455;

  printf("   a =%11d\n", a);
  printf("   b =%11d\n", b);

  sum = a + b;
  printf(" sum =%11d\n", sum);
  printf("\n");

  /* long int */
  long int la;
  long int lb;
  long int lsum;
  la = 1840083528;
  lb = 1343303455;

  printf("  la =%11ld\n", la);
  printf("  lb =%11ld\n", lb);

  lsum = la + lb;
  printf("lsum =%11ld\n", lsum);
  
  return 0;
}
  
  
