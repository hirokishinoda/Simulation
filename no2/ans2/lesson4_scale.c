#include <stdio.h>

int main(void)
{
  int i;
  float e;

  e = 1.0;
  for (i=1; 1.0+e>1; i++) {
    e = e / 2.0;
    printf("[%3d] e=%e,  %.30f\n", -1*i, e, e);
  }
  printf("e=2^(%d)\n", -(i-1));
  printf("\n");

  return 0;
}
