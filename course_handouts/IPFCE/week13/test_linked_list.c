/*
 * Test linked list class
 */

#include "linked_list.h"

#include <stdio.h>   /* printf */

void print_list(node * e)
{
  node * t = e;
  do
  {
    printf("%d ", get_value(t));
    t = get_next(t);
  }while(has_next(t));
  printf("%d\n", get_value(t));
}

int main(void)
{

  node * e1 = Initialize(1);
  node * e2 = Initialize(2);
  node * e3 = Initialize(3);
  node * e4 = Initialize(4);

  InsertAfter(e1,e2);
  InsertAfter(e2,e3);
  InsertAfter(e3,e4);

  print_list(e1);

  node * e5 = Initialize(99);
  InsertAfter(e2,e5);
  
  print_list(e1);

  node * ei = RemoveAfter(e5);
  Free(ei);

  print_list(e1);

  Free(e1);

  return 0;
}

