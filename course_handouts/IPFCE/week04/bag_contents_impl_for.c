/*
 * Count the contents of a bag
 */

#include <stdio.h>  /* scanf, printf */
#include <assert.h> /* assert */

/* program body */
int main(void)
{
    int bag[8]; 
           /* the bag of numbers */
    int s; /* sum of all numbers in the bag */
    int i; /* counter variable */
    
    /* read input */
    for (i=0; i < 8; i = i + 1)
    	scanf("%d", &bag[i]);

    /* precondition */
    /* all counts must be non-negative */
    for (i=0; i < 8; i = i + 1)
    	assert(bag[i] >= 0);
    
    /* postcondition */
    s = 0;
    for (i = 0; i < 8; i = i + 1)
    {   /* invariant: 
         * s = bag[0] + ... + bag[i-1] */
        s = s + bag[i];
    }
    /* s = bag[0] + ... + bag[7] */
    /* print output */
    printf("%d\n", s);
    
    /* return from body and exit program */
    return 0;
}