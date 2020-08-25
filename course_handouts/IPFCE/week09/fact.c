/*
 * Factorial function defined recursively
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

/* Factorial function definition */
int fact(int n)
{
  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  if(n > 1) 
    return n * fact(n - 1);
  else
    return 1;
}

int main(void)
{
  int n;
  int f;

  scanf("%d", &n);

  f = fact(n);

  printf("%d\n", f);

  return 0;
}
