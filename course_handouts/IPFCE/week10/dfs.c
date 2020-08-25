/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */

typedef enum { NONE, NUMBER, OPERATOR } command;

typedef struct node
{
        int id_num;  /* unique identifier */
	command com; /* command of the node */
	int num; /* the number if com == NUMBER */
	char op; /* the operator if com == OPERATOR */
	struct node *lchild; /* left child of operator */
	struct node *rchild; /* right child of operator */
} node;

int id_counter = 0;

/* representing not-found case */
node NULL_NODE = {NONE, 0, 0, 0, 0};

node *find_op_node(node* p, char find_op)
{
  node * ret; /* node to return */
  if(p->com == OPERATOR && p->op == find_op)
    ret = p;
  else if(p->com == NUMBER)
    ret = &NULL_NODE;
  else
  {
    ret = find_op_node(p->lchild, find_op);
    if(ret == &NULL_NODE)
      ret = find_op_node(p->rchild, find_op);
  }

  return ret;
}


/* functions to construct a tree */ 
node *make_number(int value)
{
    id_counter = id_counter + 1;
    
    node *no = (node*) malloc(sizeof(node));
    no->id_num = id_counter;
    no->com = NUMBER;
    no->num = value;
    return no;
}

node *make_operator(char op, node *left, node *right)
{
    id_counter = id_counter + 1;

    node *no = (node*) malloc(sizeof(node));
    no->id_num = id_counter;
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


void print_node(node* p)
{
  if(p == &NULL_NODE)
    printf("NULL\n");
  else if(p->com == NUMBER)
    printf("%d:[%d]\n", p->id_num, p->num);
  else if(p->com == OPERATOR)
    printf("%d:(%c)\n", p->id_num, p->op);
  else
    abort();
}

void print_tree(node* p, int depth)
{
  for(int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  print_node(p);

  if(p->com == OPERATOR)
  {
    print_tree(p->lchild, depth + 1);
    print_tree(p->rchild, depth + 1);
  }
}

int main(void)
{
    node * a;
    node * b;
    node * c;
    node * d;
  
    node *expr =
            make_operator('-',
                make_operator('/',
                    make_operator('*',
                        make_number(4),
                        make_number(6)
                    ),
                    make_operator('+',
                        make_number(33),
                        make_number(-33)
                    )
                ),
                make_operator('*',
                    make_number(6),
                    make_number(-7)
                )
            );

    printf("\n");
    print_tree(expr, 0);
    printf("\n");

    a = find_op_node(expr, '+');
    b = find_op_node(expr, '-');
    c = find_op_node(expr, '*');
    d = find_op_node(expr, '/');

    print_node(a);
    print_node(b);
    print_node(c);
    print_node(d);
    
    free_node(expr);

    return 0;
}