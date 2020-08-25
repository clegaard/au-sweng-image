/*
 * Two stacks
 */

#include "stack_safer.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack* s1; /* test stack */

  /* constructor is not called for s1 */

  Free(s1); /* destructor for s1 */

  return 0;
}