/*
 * lesson1_5 IEEE754の特殊な数
 *
 * NaN, inf -0,+0,
 *
 */

#include <stdio.h>

int main(void)
{
  double a, b;
  double c, d;

  /* NaNの生成 */
  a = 0.0/0.0;
  printf("a=%f\n", a);

  /* NaNによる演算 */
  b = 1.0+a;
  printf("b=%f\n", b);

  /* 無限大の生成 */
  a = 1.0/0.0;
  printf("a=%f\n", a);

  /* 無限大による除算 */
  b = 1.0/a;
  printf("b=%f\n", b);

  /* 正の無限大，負の無限大の生成 */
  a =  1.0/0.0;
  b = -1.0/0.0;
  printf("a=%f, b=%f\n", a, b);

  /* 符号付きゼロの生成 */
  c = 1.0/a;
  d = 1.0/b;
  printf("c=%f, d=%f\n", c, d);

  /* 符号付きゼロによる除算 */
  a = 1.0/c;
  b = 1.0/d;
  printf("a=%f, b=%f\n", a, b);
  
  return 0;
}
