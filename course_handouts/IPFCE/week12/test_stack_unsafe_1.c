/*
 * Testing the stack library
 */

#include "stack_unsafe.h"
#include <stdio.h> /* printf */

int main(void)
{
  stack s; /* test stack */
  int v1;  /* values popped */
  int v2;   
  int v3;   

  Initialize(&s);
  Push(1, &s);
  Push(2, &s);
  Push(3, &s);
  v1 = Pop(&s);
  v2 = Pop(&s);
  v3 = Pop(&s);
  printf("%d %d %d\n",v1,v2,v3);

  return 0;
}