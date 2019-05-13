#include <stdio.h>

int main(void)
{
  float a, b, c, d, eps=1.0, x, y;
  int i=0;

  x = 1.0+eps;
  while(x>1) {
    printf("[%2d] 1 + %e = %e, %.30f\n", i, eps, x, x);
    i++;
    eps/=2.0;
    x=1.0+eps;
  }

  eps *= 2.0;
  i--;

  printf("eps= %11.4e = (2^(%d))\n", eps, -i);
  a = 1.0+eps;
  b = a-1.0;
  c = 1.0+eps/2.0;
  d = c-1.0;

  printf("1+eps - 1 => %11.4e \n", b);
  printf("1+eps/2 - 1 => %11.4e \n", d);

  printf("\n");
  x = 1.0;
  printf("[%.50f]\n", x);
  printf("[%.50f]\n", eps);
  y = x + eps/2.0;
  printf("[%.50f]\n", y);
  y = x + 0.000000119;
  printf("[%.50f]\n", y);
  y = x + 0.000000071;
  printf("[%.50f]\n", y);

  return 0;
}
  
