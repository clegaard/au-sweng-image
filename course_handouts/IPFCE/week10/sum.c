/*
 * Sum function
 */

#include <stdio.h>   /* scanf, printf */
#include <assert.h>  /* assert */

int sum(int n)
{
  int i; /* counter variable */
  int r; /* result */

  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  r = 1;
  for(i = 2; i <= n; i = i + 1)
    r = i + r;

  return r;
}

int main(void)
{
  int v = sum(5);
  printf("%d\n", v);
  return 0;
}