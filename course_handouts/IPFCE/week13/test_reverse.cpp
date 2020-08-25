/*
 * Reversing an array using a stack
 */

#include "stack_class.h"
#include <stdio.h>  /* printf */
#include <assert.h> /* assert */

/* reverse order of integer array x
 * and place in integer array rev
 */
void reverse(int* x, int n, int* rev)
{
  int i; /* counter variable */

  /* pre-condition */
  assert (n > 0);

  Stack s;
  for(i = 0; i < n; i = i + 1)
    s.Push(x[i]);

  for(i = 0; !s.Empty(); i = i + 1)
    rev[i] = s.Pop();
}

int main(void)
{
  const int n = 5; /* data value count */
  int i; /* counter variable */

  int x[n] = {1,2,3,4,5};
  int y[n];

  reverse(x, n, y);

  for(i = 0; i < n; i= i + 1)
    printf("%d ", x[i]);
  printf("\n");

  for(i = 0; i < n; i= i + 1)
    printf("%d ", y[i]);

  printf("\n");
  return 0;
}