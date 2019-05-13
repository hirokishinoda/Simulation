#include <stdio.h>
#include <math.h>

int main(void)
{
  double x;
  double ans;

  x = 1e1;
  printf("x=%f\n", x);
 
  printf("%.30f\n", sqrt(x+1));
  printf("%.30f\n", sqrt(x));

  ans = sqrt(x+1) - sqrt(x);
  printf("ans=%.30f\n", ans);
  

  return 0;
}

  
  
