#include <stdio.h>   /* scanf, printf */

typedef struct {
    int x;
    int y;
} point;

/* copy the value of q into p */
void  copy_point(point *p, const point *v)
{   /* the fields of *v cannot be modified
     * only those of *p */
    p->x = v->x;
    p->y = v->y;
}

int main(void)
{
    point p;  /* point variable */
    point q = { 3, 4 }; /* initialised ... */
    
    copy_point(&p, &q);

    printf("%d %d\n", p.x, p.y); /* prints: 3 4 */

    return 0;
}