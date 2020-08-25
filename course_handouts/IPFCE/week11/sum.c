/*
 * Compute integer sum from 1 to n
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

int sum(int n)
{
  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  if(n > 1) 
    return n + sum(n - 1);
  else
    return 1;
}

int main(void)
{
  int n;
  int r;

  scanf("%d", &n);

  r = sum(n);

  printf("%d\n", r);

  return 0;
}
