/*
 * Count from 1 to n
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

int count_recursive(int n)
{
  /* pre-condition */
  assert (n > 0);

  /* post-condition */
  if(n == 1)
    return 1;
  else
    return 1 + count_recursive(n - 1);
}

int main(void)
{
  int n;  /* user input */
  int r;  /* result of function */

  scanf("%d", &n);

  r = count_recursive(n);
  printf("%d\n", r);

  return 0;
}
