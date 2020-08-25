/*
 * Compute the factorial of a given number.
 */

#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */
#include <assert.h> /* assert */

int n; /* number for which to compute the factorial */
int f; /* factorial */
int g; /* previous factorial */
int i; /* counter variable for factorial */
int j; /* counter variable for multiplication */

/* program body */
int main(void)
{
    /* read input */
    scanf("%d", &n);
    
    /* precondition */
    if (n >= 0)
        ;
    else
        abort();
    
    /* postcondition */
    i = 0;
    j = 0;
    g = 1;
    f = 1;
    while (i < n)
    {   /* invariant: f equals factorial of i
         *            0 <= i <= n
         */
        while (j < i)
        { /* invariant: g == (j + 1) * f
           *            0 <= j <= i 
           */
            assert(g == (j + 1) * f);
            g = g + f;
            j = j + 1;
        }
        f = g;
        i = i + 1;
        j = 1;
    }
    
    /* print output */
    printf("%d\n", f);
    
    /* return from body and exit program */
    return 0;
}