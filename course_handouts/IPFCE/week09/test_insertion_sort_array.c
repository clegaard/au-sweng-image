/*
 * Testing insertion sort library
 */

#include <stdio.h>                /* printf */
#include <stdbool.h>              /* bool, true, false */
#include "insertion_sort_array.h" /* isort */


bool arrays_equal(int* a, int* b, int n)
{
  int i; /* counter variable */
  for(i = 0; i < n; i = i + 1)
  {
    if(a[i] != b[i])
     return false;
  }
  return true;
}

bool test_isort()
{
  {
    const int n = 1;
    int x[n] = {1};
    isort(n,x);
    int expected_x[n] = {1};
    if(!arrays_equal(x, expected_x, n))
      return false;
  }

  {
    const int n = 2;
    int x[n] = {28,5};
    isort(n,x);
    int expected_x[n] = {5,28};
    if(!arrays_equal(x, expected_x, n))
      return false;
  }

  {
    const int n = 6;
    int x[n] = {32,18,16,28,35,9};
    isort(n,x);
    int expected_x[n] = {9, 16, 18, 28, 32, 35};
    if(!arrays_equal(x, expected_x, n))
      return false;
  }

  return true;
}

int main(void)
{
  /* test insertion sort array library */
  {
    bool success;
    success = test_isort();
    if(success)
      printf("test succeeded\n");
    else
      printf("test failed\n");
  }

  /* return from body and exit program */
  return 0;
}