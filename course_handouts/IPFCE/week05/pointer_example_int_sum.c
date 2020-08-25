#include <stdio.h>   /* scanf, printf */

void add(int *s, int x, int y)
{
    *s = x + y;
}

int main(void)
{
    int p;  /* integer variable */

    add(&p, 3 , 4);
    
    printf("%d\n", p);  /* prints: 7 */

    return 0;
}