/*
 * Stack class implemented
 * using integer array
 */

#include "stack_class.h"
#include <assert.h>      /* assert */

/* Stack constructor */
Stack::Stack()
{
  top = -1;
}

/* Stack destructor */
Stack::~Stack()
{}

/* Insert item x at the top of stack s */
void Stack::Push(int x)
{
  /* pre-condition */
  assert (top >= -1 &&
          top <  STACKSIZE);

  /* post-condition */
  top = top + 1;
  data[top] = x;
}

/* Return (and remove) the top item of stack s */
int Stack::Pop()
{
  /* pre-condition */
  assert (top >  -1 &&
          top <= STACKSIZE);

  /* post-condition */
  int v = data[top];
  top = top - 1;
  return v;
}

/* Test whether a stack can accept more pushes */
bool Stack::Full()
{
  return top >= STACKSIZE;
}

/* Test whether a stack can accept more pops */
bool Stack::Empty()
{
  return top <= -1;
}
