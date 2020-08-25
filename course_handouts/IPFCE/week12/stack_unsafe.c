/*
 * Stack data structure implemented using integer array
 */

#include "stack_unsafe.h"

/* Create an empty stack */
void Initialize(stack *s)
{
  /* pre-condition */
  /* true */

  /* post-condition */
  s->top = -1;
}

/* Insert item x at the top of stack s */
void Push(int x, stack *s)
{
  /* pre-condition */
  assert (s->top < STACKSIZE);

  /* post-condition */
  s->top = s->top + 1;
  s->data[s->top] = x;
}

/* Return (and remove) the top item of stack s */
int Pop(stack *s)
{
  /* pre-condition */
  assert (s->top >= 0);

  /* post-condition */
  int v = s->data[s->top];
  s->top = s->top - 1;
  return v;
}

/* Test whether a stack can accept more pushes */
bool Full(stack *s)
{
  return s->top == STACKSIZE;
}

/* Test whether a stack can accept more pops */
bool Empty(stack *s)
{
  return s->top == -1;
}
