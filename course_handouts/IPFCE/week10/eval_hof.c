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
int evaluate(node* p)
{
  int left_eval;  /* evaluation of left branch */
  int right_eval; /* evaluation of right branch */

  /* base case */
  if(p->com == NUMBER)
    return p->num;
  else   /* recursive step */
  {
    left_eval  = evaluate(p->lchild);
    right_eval = evaluate(p->rchild);
    
    return p->op(left_eval, right_eval);
  }
}

/* functions to construct a tree */ 
node *make_number(int value)
{
    node *no = (node*) malloc(sizeof(node));
    no->com = NUMBER;
    no->num = value;
    return no;
}

node *make_operator(Operator op, node *left, node *right)
{
    node *no = (node*) malloc(sizeof(node));
    no->com = OPERATOR;
    no->op = op;
    no->lchild = left;
    no->rchild = right;
    return no;
}

void free_node(node* p)
{
  if(p->com == NUMBER)
    free(p);
  else   /* recursive step */
  {
    free_node(p->lchild);
    free_node(p->rchild);
    free(p);
  }
}

/* some functions that conform the the Operator
 * prototype declaration
 */
int plus  (int a, int b) { return a + b;}
int minus (int a, int b) { return a - b;}
int mult  (int a, int b) { return a * b;}
int divide(int a, int b) { assert (b != 0); return a / b;}

int main(void)
{
    int v;
  
    node *expr =
            make_operator(minus,
                make_operator(mult,
                    make_operator(mult,
                        make_number(4),
                        make_number(6)
                    ),
                    make_number(8)
                ),
                make_number(98)
            );

    v = evaluate(expr);

    printf("%d\n", v);
    
    free_node(expr);

    return 0;
}