/*
 * Greatest Common Divisor algorithm defined recursively
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

/* Greatest Common Divisor */
int gcd(int a, int b)
{
  /* pre-condition */
  assert (a > 0 && b > 0);

  /* post-condition */
  if(a == b)
    return a;
  else if(a > b)
    return gcd(a - b, b);
  else
    return gcd(a, b - a);
}

int main(void)
{
  int a;
  int b;
  int f;

  scanf("%d", &a);
  scanf("%d", &b);

  f = gcd(a,b);

  printf("%d\n", f);

  return 0;
}
