/*
 * Multiply k by n
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

int count_iterative(int n)
{
  int i; /* counter variable */
  int r; /* resulting sum of integers */

  /* pre-condition */
  assert (n > 0);

  /* post-condition */
  r = 0;
  for(i = 1; i <= n; i = i + 1)
  {
    /* invariant: r = i - 1 */
    r = r + 1;
  }
  return r;
}

int main(void)
{
  int n;  /* first factor */
  int r;

  scanf("%d", &n);

  r = count_iterative(n);
  printf("%d\n", r);

  return 0;
}
