#include <stdio.h>
#include "data.h"

extern double a[N][N+1];

int main(void)
{
  int i;

  for (i=0; i<10; i++) {
    printf("%f\n", a[0][i]);
  }

  return 0;
}
