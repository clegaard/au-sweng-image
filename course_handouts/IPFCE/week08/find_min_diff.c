/*
 * Find minimum difference between values
 * in an array of unsorted integers
 */

#include <stdio.h>  /* printf */
#include <assert.h> /* assert */
#include <stdlib.h> /* abs */

#define DAY_COUNT 6

int main(void)
{
  int temp_readings[DAY_COUNT] = {32, 18, 16, 28, 35, 9};
    /* the temperature readings */
  int curr_min_diff; /* minimum temperature difference found so far */
  int next_val_i; /* next temperature value in the array */
  int next_val_j; /* next temperature value in the array */
  int next_diff;  /* next temperature difference */ 
  int i;        /* counter variable */
  int j;        /* counter variable */
  
  /* pre-condition */
  /* at least 2 temperature readings in the array */
  assert (2 <= DAY_COUNT);

  /* post-condition */
  /* for all i,j such that 0 <= i < 6, 0 <= j < 6, i != j
   *   curr_min_diff <= |temp_readings[i] - temp_readings[j]|
   */
  curr_min_diff = abs(temp_readings[0] - temp_readings[1]);
  for(i = 0; i < DAY_COUNT; i = i + 1)
  {
   for(j = 0; j < DAY_COUNT; j = j + 1)
   {
    /* invariant:
     *  for all k1,k2 such that
     *    0 <= k1 <= i, 0 <= k2 <= j, i != j: 
     *      curr_min_diff <= |temp_readings[k1] - temp_readings[k2]|
     */

     if(i == j)
      continue; /* do not compare temp values to themselves */

     next_val_i = temp_readings[i];
     next_val_j = temp_readings[j];
     next_diff = abs(next_val_i - next_val_j);

     if(next_diff < curr_min_diff)
       curr_min_diff = next_diff;
   }
  }
  
  /* print minimum difference to console */
  printf("%d\n", curr_min_diff);

  return 0;
}