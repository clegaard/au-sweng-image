/*
 * Evaluate an expression recursively.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */

typedef enum { NUMBER, OPERATOR } command;

typedef struct node
{
	command com; /* command of the node */
	int num; /* the number if com == NUMBER */
	char op; /* the operator if com == OPERATOR */
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
    
    switch (p->op)
    {
      case '+': return left_eval + right_eval;
      case '-': return left_eval - right_eval;
      case '*': return left_eval * right_eval;
      case '/': return left_eval / right_eval;
      default:  abort();
    }
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

node *make_operator(char op, node *left, node *right)
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

int main(void)
{
    int v;
  
    node *expr =
            make_operator('-',
                make_operator('*',
                    make_operator('*',
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