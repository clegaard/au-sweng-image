/*
 * Breaking the stack library
 */

#include "stack_unsafe.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack s; /* test stack */
  int v;   /* popped value */

  Initialize(&s);
  s.top = 500;
  v = Pop(&s);

  return 0;
}