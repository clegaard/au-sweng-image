#include <stdio.h>   /* scanf, printf */

typedef int * intp;

int main(void)
{
    int p;  /* integer variable */
    intp q; /* integer pointer variable */

    q = &p; /* q points to p */
    
    p = 1;
    printf("%d\n", *q); /* prints: 1 */
    
    *q = 2;
    printf("%d\n", p);  /* prints: 2 */

    return 0;
}