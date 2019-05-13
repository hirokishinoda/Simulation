/*
 * No2
 *
 * 丸め語差
 *
 * 0.1を100万回足しても，10万にならない．
 * 
 */

#include <stdio.h>

#define ITERATION 1000000

int main(void)
{
  int i;
  double sum;
  double a;

  sum = 0.0;
  for (i=0; i<ITERATION; i++) {
    sum += 0.1;
  }
  
  printf("sum=%f\n", sum);

  a = 0.1;
  printf("a = %f\n", a);
  printf("a = %.30f\n", a);

  return 0;
}
