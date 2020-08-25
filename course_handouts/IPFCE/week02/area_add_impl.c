/*
 * Compute the area of a given rectangle.
 */

#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */

int m; /* width of the rectangle */
int n; /* height of the rectangle */
int a; /* the area of the rectangle */
int i; /* the number of repetitions */

/* program body */
int main(void)
{
    /* read input */
    scanf("%d", &m);
    scanf("%d", &n);
    
    /* precondition */
    if (m >= 0 && n >= 0)
    	;
    else
    	abort();
    
    /* postcondition */
    i = 0;
    a = 0;
    while (i < n)
    {
    	a = a + m;
    	i = i + 1;
    }
    
    /* print output */
    printf("%d\n", a);
    
    /* return from body and exit program */
    return 0;
}