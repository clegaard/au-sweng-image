/*
 * Evaluation of an expression using pointers.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>   /* abort */

typedef enum { ROOT, NUMBER, OPERATOR } command;

typedef enum { WHITE, GREY, BLACK } shade;

typedef struct node
{
	command com; /* command of the node */
	int num; /* the number if com == NUMBER */
	char op; /* the operator if com == OPERATOR */
	struct node *lchild; /* left child of operator */
	struct node *rchild; /* right child of operator */
	shade mark; /* each field is marked with a shade for evaluation */
} node;

node *make_root(node *expr)
{
    node *no = (node*) malloc(sizeof(node));
    no->com = ROOT;
    no->lchild = expr;
    no->mark = WHITE;
}

node *make_number(int value)
{
    node *no = (node*) malloc(sizeof(node));
    no->com = NUMBER;
    no->num = value;
    no->mark = WHITE;
}

node *make_operator(char op, node *left, node *right)
{
    node *no = (node*) malloc(sizeof(node));
    no->com = OPERATOR;
    no->op = op;
    no->lchild = left;
    no->rchild = right;
    no->mark = WHITE;
}

node *make_expression()
{
    node *expr =
        make_root(
            make_operator('-',
                make_operator('*',
                    make_operator('*',
                        make_number(4),
                        make_number(6)
                    ),
                    make_number(8)
                ),
                make_number(98)
            )
        );
}

void initialise(node **pp, node **qq)
{
    *qq = *pp;
    *pp = (*qq)->lchild;
}

void copy_result(node *p)
{
    p->num = p->lchild->num;
}

void backtrack_left(node **pp, node **qq)
{
    node *r;
    r = (*qq)->lchild;
    (*qq)->lchild = *pp;
    *pp = *qq;
    *qq = r;
}

void backtrack_right(node **pp, node **qq)
{
    node *r;
    r = (*qq)->rchild;
    (*qq)->rchild = *pp;
    *pp = *qq;
    *qq = r;
}

void backtrack(node **pp, node **qq)
{
    switch ((*qq)->mark)
    {
    case GREY:
        backtrack_left(pp, qq);
        break;
    case BLACK:
        backtrack_right(pp, qq);
        break;
    default:
        abort();
    }
}

void go_left(node **pp, node **qq)
{
    node *r;
    r = (*pp)->lchild;
    (*pp)->lchild = *qq;
    *qq = *pp;
    *pp = r;
}

void go_right(node **pp, node **qq)
{
    node *r;
    r = (*pp)->rchild;
    (*pp)->rchild = *qq;
    *qq = *pp;
    *pp = r;
}

void evaluate(node *p)
{
    switch (p->op)
    {
        case '+':
            p->num = p->lchild->num + p->rchild->num;
            break;
        case '-':
            p->num = p->lchild->num - p->rchild->num;
            break;
        case '*':
            p->num = p->lchild->num * p->rchild->num;
            break;
        case '/':
            p->num = p->lchild->num / p->rchild->num;
            break;
        default:
            abort();
    }
}

int main(void)
{
    node *root = make_expression();

    node *p;
    node *q;
    
    p = root;
    q = NULL;
    
    while (p != NULL)
    {
        switch (p->com)
        {
        case ROOT:
            switch (p->mark)
            {
            case WHITE:
                p->mark = BLACK;
                initialise(&p, &q);
                break;
            case BLACK:
                copy_result(p);
                p = NULL;
                break;
            default:
                abort();
            }
            break;
        case NUMBER:
            p->mark = BLACK;
            backtrack(&p, &q);
            break;
        case OPERATOR:
            switch (p->mark)
            {
            case WHITE:
                p->mark = GREY;
                go_left(&p, &q);
                break;
            case GREY:
                p->mark = BLACK;
                go_right(&p, &q);
                break;
            case BLACK:
                evaluate(p);
                backtrack(&p, &q);
                break;
            default:
                abort();
            }
            break;
        default:
            abort();
        }
    }

    printf("%d\n", root->num);
    
    return 0;
}
