/*
 * Count from 1 to n
 */

#include <assert.h>  /* assert */
#include <stdio.h>   /* printf */

int count_tail_recursive(int n, int running_total)
{
  /* pre-condition */
  assert (n > 0);

  /* post-condition */
  if(n == 1)
    return 1 + running_total;
  else
    return count_tail_recursive(n - 1, 1 + running_total);
}

int main(void)
{
  int n;  /* user input */
  int r;  /* result of function */

  scanf("%d", &n);

  r = count_tail_recursive(n, 0);
  printf("%d\n", r);

  return 0;
}
