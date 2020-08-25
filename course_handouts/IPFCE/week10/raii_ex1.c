/*
 * Function to apply operator to linked list of integers
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <assert.h>  /* assert */

typedef struct node
{
  int value;
  struct node* next;
} node;

/* terminal node at the end of the list */
node SENTINEL = {0, 0};

/* utility functions to create and free lists */
node * make_node(int v, node * q)
{
  node* p = (node*) malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

void free_node(node* p)
{
  if(p == &SENTINEL)
    return;
  else
  {
    free_node(p->next);
    free(p);
  }
}

/* declare function prototype to give as
 * input to the 'apply' function
 */
typedef int (* Operator) (int arg1, int arg2);

int apply(node* p, Operator op )
{
  int r; /* result */

  /* pre-condition */
  assert (p != &SENTINEL);

  /* post-condition */
  r = p->value;
  p = p->next;
  for(; p != &SENTINEL; p = p->next)
    r = op(r, p->value);

  return r;
}

/* some functions that conform the the Operator
 * prototype declaration
 */
int plus(int a, int b)
{
  return a + b;
}

int mult(int a, int b)
{
  return a * b;
}

int divide(int a, int b)
{
  assert (b != 0);
  return a / b;
}

int main(void)
{
  int quo;  /* quotient of values */

  node* list =	make_node(4,
		 make_node(6,
 		  make_node(0,
		   make_node(51,
		    make_node(-2,
		              &SENTINEL
                    )
                   )
                  )
                 )
                );

  quo  = apply(list, divide);

  printf("%d\n", quo);

  free_node(list);

  return 0;
}