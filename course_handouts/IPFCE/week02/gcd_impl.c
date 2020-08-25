/* Compute the gcd of two positive numbers. */

#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */

int x; /* first number */
int y; /* second number */
int m; /* resulting gcd */
int n; /* auxiliary variable */

int main(void)
{
    scanf("%d", &x);
    scanf("%d", &y);
    
    /* precondition */
    if (x > 0 && y > 0)
        ;
    else
        abort();
    
    /* postcondition */
    m = x;
    n = y;
    while (m != n)
    {   /* invariant: gcd(m,n) == gcd(x,y) */
        if (m > n)     /* gcd(m,n) ... */
            m = m - n; /* == gcd(m - n, n) */
        else
            n = n - m; /* == gcd(m, n - m) */
    }
    /* m = gcd(x,y) */
    printf("%d\n", m);
    
    return 0;
}