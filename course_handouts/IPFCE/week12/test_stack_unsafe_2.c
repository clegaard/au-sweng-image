/*
 * Breaking the stack library
 */

#include "stack_unsafe.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack s; /* test stack */

  Initialize(&s);
  s.top = 500;
  if(Full(&s))
    printf("Stack if full\n");
  else
    printf("Stack if NOT full\n");

  return 0;
}