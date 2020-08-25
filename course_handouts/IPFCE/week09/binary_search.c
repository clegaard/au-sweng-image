/*
 * Binary search as a recursive function
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */
#include <stdbool.h> /* bool, true, false */

/* Binary search function */
bool binary_search(int v, int* X, int low, int high)
{
  int mid;     /* middle index */
  int mid_val; /* middle value */

  /* pre-condition */
  assert (0 <= low);

  /* post-condition */
  mid = (low + high) / 2;
  mid_val = X[mid];

  /* base cases */
  if(low > high)
    return false;

  else if(v == mid_val)
    return true;

  /* recursive steps */
  else if(v < mid_val)
    return binary_search(v, X, low, mid - 1);

  else
    return binary_search(v, X, mid + 1, high);
}

int main(void)
{
  const int n = 6;
  int X[n] = {9,16,18,28,32,35};
  int v;
  bool has;

  scanf("%d", &v);

  has = binary_search(v, X, 0, n - 1);

  if(has)
    printf("Value is in array\n");
  else
    printf("Value is NOT in array\n");

  return 0;
}
