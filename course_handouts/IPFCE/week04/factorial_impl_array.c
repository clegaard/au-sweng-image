/*
 * Compute the factorial of a given number.
 */

#include <stdio.h>  /* scanf, printf */
#include <assert.h> /* assert */

int n; /* number for which to compute the factorial */
int a[13]; /* factorial numbers from 0 onwards */
int i; /* counter variable for factorial */
int j; /* counter variable for multiplication */

/* program body */
int main(void)
{
    /* read input */
    scanf("%d", &n);
    
    /* precondition */
    assert(n >= 0 && n <= 12);
    
    /* postcondition */
    a[0] = 1;
    for (i = 0; i < n; i = i + 1)
    {   /* invariant: a[i] equals factorial of i
         *            0 <= i <= n
         */
        a[i+1] = a[i];
        for (j = 0; j < i; j = j + 1)
        { /* invariant: a[i+1] = (j + 1) * a[i]
           *            0 <= j <= i 
           */
            a[i+1] = a[i+1] + a[i];
        }
    }
    /* a[n] equals factorial of n */
    /* print output */
    for (i = 0; i <= n; i = i + 1)
    	printf("%d\n", a[i]);
    
    /* return from body and exit program */
    return 0;
}