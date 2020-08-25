/*
 * Compute the factorial of a given number.
 */

#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */

int n; /* number for which to compute the factorial */
int f; /* factorial */
int i; /* counter variable */

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
    f = 1;
    while (i < n)
    {	/* invariant: f equals factorial of i */
    	i = i + 1;
    	f = f * i;
    }
    
    /* print output */
    printf("%d\n", f);
    
    /* return from body and exit program */
    return 0;
}