/*
 * Two stacks
 */

#include "stack_safer.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack* s1; /* some stacks */
  stack* s2;

  s1 = Initialize();
  s2 = Initialize();

  Push(1, s1);
  Push(2, s1);
  Push(3, s1);

  Push(4, s2);
  Push(5, s2);
  Push(6, s2);
  
  printf("\nStack s1:");
  while(!Empty(s1))
    printf("%d ", Pop(s1));

  printf("\nStack s2:");
  while(!Empty(s2))
    printf("%d ", Pop(s2));
  printf("\n");   

  Free(s1);
  Free(s2);
  return 0;
}