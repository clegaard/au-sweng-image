/*
 * Concatenate two strings.
 */

#include <stdio.h>  /* scanf, printf */

/* program body */
int main(void)
{
    char pre[4] = "pre";
    char cond[10] = "condition";
    char precond[13]; /* concatenated string */
    int i; /* counter variable */
    int j; /* counter variable with offset */
    
    /* precondition */
    /* true */
    
    /* postcondition */
    for (i = 0; pre[i] != 0; i = i + 1)
    {   /* invariant: for all k such that 0 <= k < i,
         * 				precond[i] == pre[i]
         */
        precond[i] = pre[i];
    }
    /* for all k such that 0 <= k < i, precond[i] == pre[i] */
    /* i == 3 */
    for (j = i; cond[j-i] != 0; j = j + 1)
    {   /* invariant: for all k such that i <= k < j,
         * 				precond[j] == cond[j-i]
         */
        precond[j] = cond[j-i];
    }
    /* for all k such that 0 <= k < i, precond[i] == pre[i] */
    /* for all k such that i <= k < j, precond[j] == cond[j-i] */
    /* j == 12 */
    precond[j] = 0; /* set trailing 0 */
    /* precond = "precondition" */
    /* print output */
    for(i = 0; precond[i] != 0; i = i + 1)
    	printf("%c", precond[i]);
    printf("\n");
    
    /* return from body and exit program */
    return 0;
}