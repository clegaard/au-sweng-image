/*
 * Compute Fibonacci numbers recursively
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

int fib(int n)
{
  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  if(n == 1) 
    return 1;
  else if(n == 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
  int i; /* counter variable */
  for(i = 1; i < 10; i = i + 1)
    printf("%d, ", fib(i));
  printf("...\n");

  return 0;
}
