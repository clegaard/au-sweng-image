/*
 * Compute the factorial of a given number.
 */

#include <stdio.h>  /* scanf, printf */
#include <assert.h> /* assert */

/* program body */
int main(void)
{
 	char message[15] = "test succeeded";
 	int i;

    /* print output */
    for (i = 0; i < 15; i = i + 1)
    	printf("%u, ", message[i]);
    
    /* return from body and exit program */
    return 0;
}