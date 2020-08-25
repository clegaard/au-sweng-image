/* Compute the gcd of two positive numbers. */

#include <stdbool.h> /* bool, tyre, false */
#include <stdio.h>   /* scanf, printf */
#include <assert.h>  /* assert */

int gcd(int x, int y)
{
	int m; /* resulting gcd */
	int n; /* auxiliary variable */

    /* precondition */
    assert (x > 0 && y > 0);
    
    /* postcondition */
    m = x;
    n = y;
    while (m != n)
    {   /* invariant: gcd(m,n) == gcd(x,y) */
        if (m > n)     /* gcd(m,n) ... */
            m = m - n; /* == gcd(m - n, n) */
        else
            n = n - m; /* == gcd(m, n - m) */
    }
    /* m = gcd(x,y) */
    return m;
}

bool test_gcd(void)
{
	{
		int m;
		m = gcd(1, 1);
		if (m != 1)
			return false;
	}
	{
		int m;
		m = gcd(2, 3);
		if (m != 1)
			return false;
	}
	{
		int m;
		m = gcd(3, 2);
		if (m != 1)
			return false;
	}
	{
		/* Currently, we have no means
		 * to test failing assertions
		 */
	}
	return true;
}

int main(void)
{
	int x; /* first number */
	int y; /* second number */
	int m; /* resulting gcd */

    /* test function gcd */
    {
    	bool success;
    	success = test_gcd();
    	if (success)
    		printf("test succeeded\n");
    	else
    		printf("test failed\n");
    }
    
    /* read input */
    scanf("%d", &x);
    scanf("%d", &y);
    
    /* call gcd function */
    m = gcd(x, y);
    
    /* print output */
    printf("%d\n", m);
    
    return 0;
}