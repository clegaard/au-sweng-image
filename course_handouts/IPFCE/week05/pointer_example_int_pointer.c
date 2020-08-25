#include <stdio.h>   /* scanf, printf */

void set_value(int **s, int x)
{
    int *r; /* integer pointer variable */
    r = *s; /* if s == &q, then r == &p */
    *r = x; /*         ... and p == x   */
}

int main(void)
{
    int p;  /* integer variable */
    int *q; /* integer pointer variable */
    
    q = &p;

    set_value(&q, 7);
    
    printf("%d\n", p);  /* prints: 7 */

    return 0;
}