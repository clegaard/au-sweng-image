/*
 * Compute the factorial of a given number.
 */

#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */

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


    g = 1;
    f = 1;
    for (i = 0; i < n; i = i + 1)
    {   /* invariant: f equals factorial of i
         *            0 <= i <= n
         */
        for (j = 0; j < i; j = j + 1)
        { /* invariant: g = (j + 1) * f
           *            0 <= j <= i 
           */
            g = g + f;
            
        }
        f = g;
        
        
    }
    
    /* print output */
    printf("%d\n", f);
    
    /* return from body and exit program */
    return 0;
}