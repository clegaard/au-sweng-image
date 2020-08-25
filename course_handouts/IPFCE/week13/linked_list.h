/*
 * Linked list class in C
 */

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h> /* true, false, bool */

typedef struct st_node node;

/* node constructor */
node * Initialize(int v);

/* node destructor */
void Free(node* p);

/* insert node q after p */
void InsertAfter(node * p, node * q);

/* remove and return node after p */
node * RemoveAfter(node * p);

/* getters */
int    get_value(node * p);
node * get_next(node * p);
bool   has_next(node * p);

/* setters */
void set_value(node * p, int v);

#endif
