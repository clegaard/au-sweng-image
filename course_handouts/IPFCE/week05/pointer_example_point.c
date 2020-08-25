#include <stdio.h>   /* scanf, printf */

typedef struct {
    int x;
    int y;
} point;

int main(void)
{
    point p;  /* point variable */
    point *q; /* point pointer variable */
    
    q = &p; /* q points to p */

    p.x = 1;
    p.y = 1;
    printf("%d %d\n", q->x, q->y); /* prints: 1 1 */
    
    q->x = 2;
    q->y = 2;
    printf("%d %d\n", p.x, p.y);   /* prints: 2 2 */

    return 0;
}