/*
 * Evaluation of an expression using pointers.
 */


// motivate OO methodology!

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>   /* abort */

#define SIZE 8 /* size of the expression array */
#define ROOT_NODE 0 /* index of the root node */
#define EXPR_NODE 1 /* index of the child of the root node */
#define SENTINEL -1 /* sentinel signalling that the evaluation has finished */

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

node no06 = { NUMBER, 6, 0, NULL, NULL, WHITE };
node no04 = { NUMBER, 4, 0, NULL, NULL, WHITE };
node no08 = { NUMBER, 8, 0, NULL, NULL, WHITE };
node op03 = { OPERATOR, 0, '*', &no04, &no06, WHITE };
node no98 = { NUMBER, 98, 0, NULL, NULL, WHITE };
node op02 = { OPERATOR, 0, '*', &op03, &no08, WHITE };
node op01 = { OPERATOR, 0, '-', &op02, &no98, WHITE };
node root = { ROOT, 0, 0, &op01, NULL, WHITE };

void initialise(node **pp, node **qq)
{
    *qq = *pp;
    *pp = (*qq)->lchild;

}

void copy_result(node *p)
{
    p->num = p->lchild->num;
}

void backtrack(node **pp, node **qq)
{
    node *p = *pp;
    node *q = *qq;
    node *r;
    r = p;
    p = q;
    switch (p->mark)
    {
    case GREY:
        q = p->lchild;
        p->lchild = r;
        break;
    case BLACK:
        q = p->rchild;
        p->rchild = r;
        break;
    default:
        abort();
    }
    *pp = p;
    *qq = q;
}

void go_left(node **pp, node **qq)
{
    node *p = *pp;
    node *q = *qq;
    node *r;
    if (p->lchild != NULL)
    {
        r = p->lchild;
        p->lchild = q;
        q = p;
        p = r;
    }
    *pp = p;
    *qq = q;
}

void go_right(node **pp, node **qq)
{
    node *p = *pp;
    node *q = *qq;
    node *r;
    if (p->rchild != NULL)
    {
        r = p->rchild;
        p->rchild = q;
        q = p;
        p = r;
    }
    *pp = p;
    *qq = q;
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

    node *p;
    node *q;
    
    p = &root;
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

    printf("%d\n", root.num);
    
    return 0;
}