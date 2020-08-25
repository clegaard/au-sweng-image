/*
 * Function to apply operator to integers 1 to n
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <assert.h>  /* assert */

/* declare function prototype to give as
 * input to the 'apply' function
 */
typedef int (* Operator) (int arg1, int arg2);

int apply(int n, Operator op )
{
  int i; /* counter variable */
  int r; /* result */

  /* pre-condition */
  assert (n >= 1);

  /* post-condition */
  r = 1;
  for(i = 2; i <= n; i = i + 1)
    r = op(i, r);

  return r;
}

/* some functions that conform the the Operator
 * prototype declaration
 */
int plus(int a, int b)
{
  return a + b;
}

int mult(int a, int b)
{
  return a * b;
}

int main(void)
{
  int sum;  /* value of sum 1 to n */
  int prod; /* value of product 1 to n */
  int n;    /* user given n */

  scanf("%d", &n);

  sum  = apply(n, plus);
  prod = apply(n, mult);

  printf("%d\n", sum);
  printf("%d\n", prod);

  return 0;
}