/*
 * Function to apply operator to integer array
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <assert.h>  /* assert */

/* declare function prototype to give as
 * input to the 'apply' function
 */
typedef int (* Operator) (int arg1, int arg2);

int apply(int * X, int n, Operator op )
{
  int i; /* counter variable */
  int r; /* result */

  /* pre-condition */
  assert (n > 0);

  /* post-condition */
  r = X[0];
  for(i = 1; i < n; i = i + 1)
    r = op(X[i], r);

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

  const int n = 5; /* number of values in array */
  int X[5] = {4,6,1,51,-2};
    /* array of data values */

  sum  = apply(X, n, plus);
  prod = apply(X, n, mult);

  printf("%d\n", sum);
  printf("%d\n", prod);

  return 0;
}