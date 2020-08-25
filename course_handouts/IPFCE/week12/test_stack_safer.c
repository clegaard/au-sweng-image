/*
 * Testing the C stack class
 */

#include "stack_safer.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack* s; /* test stack */

  s = Initialize();
  Push(1, s);
  Push(2, s);
  Push(3, s);

  printf("\n");
  while(!Empty(s))
   printf("%d ", Pop(s));
  printf("\n");

  Free(s);  /* clean up */
  return 0;
}