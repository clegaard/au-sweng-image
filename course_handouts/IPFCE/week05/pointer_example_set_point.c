#include <stdio.h>   /* scanf, printf */

typedef struct {
    int x;
    int y;
} point;

void set_point(point *q, int x, int y)
{
    q->x = x;
    q->y = y;
}

int main(void)
{
    point p;  /* point variable */
    
    set_point(&p, 3, 4);

    printf("%d %d\n", p.x, p.y);   /* prints: 3 4 */

    return 0;
}