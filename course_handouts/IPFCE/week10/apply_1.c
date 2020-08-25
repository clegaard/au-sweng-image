/*
 * Function to apply operator to integers 1 to n
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <assert.h>  /* assert */

int apply(int n, char op)
{
  int i; /* counter variable */
  int r; /* result */

  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  r = 1;
  for(i = 2; i <= n; i = i + 1)
  {
    switch(op)
    {
      case '*':
        r = i * r;
        break;
      case '+':
        r = i + r;
        break;
      default:
        abort();
    }
  }

  return r;
}

int main(void)
{
  int v1 = apply(5, '*');
  printf("%d\n", v1);
  int v2 = apply(5, '+');
  printf("%d\n", v2);
  return 0;
}