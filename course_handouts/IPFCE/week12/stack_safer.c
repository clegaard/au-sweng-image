/*
 * stack data structure implemented
 * using integer array
 */

#include "stack_safer.h"

#define STACKSIZE 10

struct st_stack
{
  int  data[STACKSIZE + 1];
  int  top;
};

/* Create an empty stack */
stack* Initialize()
{
  /* pre-condition */
  /* true */

  /* post-condition */
  stack * s = malloc(sizeof(stack));
  s->top = -1;
  return s;
}

/* Insert item x at the top of stack s */
void Push(int x, stack *s)
{
  /* pre-condition */
  assert (s->top >= -1 &&
          s->top <  STACKSIZE);

  /* post-condition */
  s->top = s->top + 1;
  s->data[s->top] = x;
}

/* Return (and remove) the top item of stack s */
int Pop(stack *s)
{
  /* pre-condition */
  assert (s->top >  -1 &&
          s->top <= STACKSIZE);

  /* post-condition */
  int v = s->data[s->top];
  s->top = s->top - 1;
  return v;
}

/* Test whether a stack can accept more pushes */
bool Full(stack *s)
{
  return s->top >= STACKSIZE;
}

/* Test whether a stack can accept more pops */
bool Empty(stack *s)
{
  return s->top <= -1;
}

/* Free the stack */
void Free(stack *s)
{
  free(s);
}
