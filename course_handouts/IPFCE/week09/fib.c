/*
 * Fibonacci numbers defined recursively
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

/* Fibonacci function definition */
int fib(int n)
{
  /* pre-condition */
  assert (n >= 0);

  /* post-condition */
  if(n > 1) 
    return fib(n - 1) + fib(n - 2);
  else if(n == 1)
    return 1;
  else
    return 0;
}

int main(void)
{
  int n;
  int f;

  scanf("%d", &n);

  f = fib(n);

  printf("%d\n", f);

  return 0;
}
