/*
 * Multiply two matrices.
 */

#include <stdio.h>  /* scanf, printf */

/* program body */
int main(void)
{
    int a[2][4] = { { 1, 2, 3, 4}, { 4, 3, 2, 1} };
    int b[4][3] = { { 1, 0, 0 }, { 1, 1, 0 }, { 0, 1, 1 }, { 0, 0, 1 } };
    int c[2][3]; /* result of the multiplication */
    int i; /* counter variable for the rows of c */
    int j; /* counter variable for the columns of c */
    int k; /* counter variable for the sum */

    /* precondition */
    /* true */

    /* postcondition */
    /* compute product of matrices a and b
     * according to the formula on the slides
     */
    for (i = 0; i < 2; i = i + 1)
        for (j = 0; j < 3; j = j + 1)
        {
        	c[i][j] = 0;
        	for (k = 0; k < 4; k = k + 1)
        		c[i][j] = c[i][j] + a[i][k] * b[k][j];
        }

    /* print output */
    for (i = 0; i < 2; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
    		printf("%d ", c[i][j]);
    	printf("\n");
    }

    /* return from body and exit program */
    return 0;
}