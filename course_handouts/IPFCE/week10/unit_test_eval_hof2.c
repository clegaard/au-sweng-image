/*
 * Evaluate an expression recursively.
 */

#include "eval_hof2.h"
#include <stdbool.h>

bool test_plus(void)
{
  { /* testing two positives */
    int a = 5;
    int b = 6;
    int expected = 11;
    if(plus(a,b) != expected)
      return false;
  }

  { /* testing two negatives */
    int a = -5;
    int b = -6;
    int expected = -11;
    if(plus(a,b) != expected)
      return false;
  }

  { /* testing positive and negative */
    int a = 5;
    int b = -6;
    int expected = -1;
    if(plus(a,b) != expected)
      return false;
  }


  return true;
}

bool test_all(void)
{
  if(!test_plus())
    return false;

  return true;
}

int main(void)
{
    /* test function gcd */
    {
    	bool success;
    	success = test_all();
    	if (success)
    		printf("test succeeded\n");
    	else
    		printf("test failed\n");
    }
    
    return 0;
}

