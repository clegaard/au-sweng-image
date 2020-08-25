/*
 * Factorial function defined recursively
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

/* Factorial function definition */
int fact(int n)
{
  int i; /* counter variable */
  int f; /* factorial */

  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  f = 1;
  for(i = 1; i <= n; i = i + 1)
  {
    f = i * f;
  }
  return f;    
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
