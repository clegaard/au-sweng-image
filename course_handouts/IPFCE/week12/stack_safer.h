/*
 * Stack data structure implemented
 * using integer array
 */

#ifndef _STACK_SAFER_H_
#define _STACK_SAFER_H_

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <stdbool.h> /* bool, true, false */
#include <stdlib.h>  /* malloc, free */

typedef struct st_stack stack;

/* Create an empty stack */
stack* Initialize();

/* Insert item x at the top of stack s */
void Push(int x, stack *s);

/* Return (and remove) the top item of stack s */
int Pop(stack *s);

/* Test whether a stack can accept more pushes */
bool Full(stack *s);

/* Test whether a stack can accept more pops */
bool Empty(stack *s);

/* Free the stack */
void Free(stack *s);

#endif