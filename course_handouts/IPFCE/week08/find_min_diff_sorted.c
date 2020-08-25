/*
 * Find minimum difference between values
 * in an array of sorted integers
 */

#include <stdio.h>  /* printf */
#include <assert.h> /* assert */

#define DAY_COUNT 6

int main(void)
{
  int sorted_temp_readings[DAY_COUNT] = {9, 16, 18, 28, 32, 35};
    /* the temperature readings in ascending order */
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
  /* for all i,j such that 0 <= i < 6, j = i + 1
   *   curr_min_diff <= sorted_temp_readings[j] - sorted_temp_readings[i]
   */
  curr_min_diff = sorted_temp_readings[1] - sorted_temp_readings[0];
  for(i = 0; i < DAY_COUNT - 1; i = i + 1)
  {
    /* invariant:
     *  for all k1,k2 such that
     *    0 <= k1 <= i, k2 = k1 + 1
     *      curr_min_diff <=   sorted_temp_readings[k2]
     *                       - sorted_temp_readings[k1]
     */
     j = i + 1;
     next_val_i = sorted_temp_readings[i];
     next_val_j = sorted_temp_readings[j];
     next_diff = next_val_j - next_val_i;

     if(next_diff < curr_min_diff)
       curr_min_diff = next_diff;
  }
  
  /* print minimum difference to console */
  printf("%d\n", curr_min_diff);

  return 0;
}