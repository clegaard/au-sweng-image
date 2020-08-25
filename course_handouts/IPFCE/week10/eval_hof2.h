/*
 * Evaluate an expression recursively.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <assert.h>  /* assert */

typedef int (* Operator) (int arg1, int arg2);

typedef enum { NUMBER, OPERATOR } command;

typedef struct node
{
	command com; /* command of the node */
	int num; /* the number if com == NUMBER */
	Operator op; /* the operator function if com == OPERATOR */
	struct node *lchild; /* left child of operator */
	struct node *rchild; /* right child of operator */
} node;

/* evaluate the expression */
int evaluate(node* p);

/* functions to construct a tree */ 
node *make_number(int value);

node *make_operator(Operator op, node *left, node *right);

void free_node(node* p);

/* some functions that conform the the Operator
 * prototype declaration
 */
int plus  (int a, int b);
int minus (int a, int b);
int mult  (int a, int b);
int divide(int a, int b);

