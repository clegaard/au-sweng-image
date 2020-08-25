/*
 * Breaking the stack library
 */

#include "stack_safer.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack* s; /* test stack */
  s = Initialize();

  /* The compiler throws errors when
   * trying to compile these two instructions,
   * top and data are not defined for stack
   * in the header file
   */
   
  /* s->top = 5; */
  /* s->data[1] = 99; */
   
  return 0;
}