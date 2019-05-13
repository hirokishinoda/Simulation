/*
 * No5
 * 
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
  double a;
  double b;
  double c;

  a = 0.00000001234;
  b = 3141593;

  printf("  a = %.11f\n", a);
  printf("  b = %.11f\n", b);

  c = a + b;
  printf("a+b = %.11f\n", c);


  a = 0.00000001234;
  c = a + a;
  printf("a+a = %.11f\n", c);

  return 0;
}

  
  
