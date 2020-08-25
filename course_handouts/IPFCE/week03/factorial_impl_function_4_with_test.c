/*
 * Compute the factorial of a given number.
 */

#include <stdbool.h> /* bool, tyre, false */
#include <stdio.h>   /* scanf, printf */
#include <assert.h>  /* assert */

int fact(int n)
{
    int f; /* factorial */
    int g; /* previous factorial */
    int i; /* counter variable for factorial */
    int j; /* counter variable for multiplication */
    /* precondition */
    assert(n >= 0);
    
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
    return f;
}

bool test_fact(void)
{
	// n = 0, result = 1
	{
		int r;
		r = fact(0);
		if (r != 1)
			return false;
	}
	// n = 1, result = 1
	{
		int r;
		r = fact(1);
		if (r != 1)
			return false;
	}
	// n = 2, result = 2
	{
		int r;
		r = fact(2);
		if (r != 2)
			return false;
	}
	return true;
}

/* program body */
int main(void)
{
    int n; /* number for which to compute the factorial */
    int f; /* factorial */
    
    /* test function fact */
    {
    	bool success;
    	success = test_fact();
    	if (success)
    		printf("test succeeded\n");
    	else
    		printf("test failed\n");
    }
    
    /* read input */
    scanf("%d", &n);
    
    /* call the function */
    f = fact(n);
    
    /* print output */
    printf("%d\n", f);
    
    /* return from body and exit program */
    return 0;
}