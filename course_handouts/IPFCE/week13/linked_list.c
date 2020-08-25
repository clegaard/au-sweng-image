/*
 * Linked list class in C
 */

#include "linked_list.h"
#include <stdlib.h>  /* malloc, free */
#include <assert.h>  /* assert */
#include <stdbool.h> /* true, false, bool */

typedef struct st_node
{
   int value;
   struct st_node * next;
} node;

/* terminal node at the end of the list */
node SENTINEL = {0, 0};

/* node constructor */
node * Initialize(int v)
{
  node* p = malloc(sizeof(node));
  p->value = v;
  p->next = &SENTINEL;
  return p;
}

/* node destructor */
void Free(node* p)
{
  node* q = p;
  while(q != &SENTINEL)
  {
    node * t = q->next;
    free(q);
    q = t;
  }
}

/* getters */
int get_value(node * p)
{
  return p->value;
}

node * get_next(node * p)
{
  assert (p->next != &SENTINEL);
  return p->next;
}

bool has_next(node * p)
{
  return p->next != &SENTINEL;
}

/* setters */
void set_value(node * p, int v)
{
  p->value = v;
}

/* insert node q after p */
void InsertAfter(node * p, node * q)
{
  /* pre-condition */
  assert (p != &SENTINEL);

  /* post-condition */
  q->next = p->next;
  p->next = q;
}

/* remove and return node after p */
node * RemoveAfter(node * p)
{
  /* pre-condition */
  assert (p->next != &SENTINEL);

  /* post-condition */
  node * q = p->next;
  p->next = q->next;
  q->next = &SENTINEL;
  return q;
}

