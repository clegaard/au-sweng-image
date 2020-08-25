/*
 * Find minimum value in an array of integers
 */

#include <stdio.h>  /* printf */
#include <assert.h> /* assert */

#define DAY_COUNT 6

int main(void)
{
  int sorted_temp_readings[DAY_COUNT] = {9, 16, 18, 28, 32, 35};
    /* the temperature readings in ascending order */
  int min_val; /* minimum value in the array */  

  /* pre-condition */
  /* at least 1 temperature reading in the array */
  assert (1 <= DAY_COUNT);

  /* post-condition */
  /* for all i such that 0 <= i < 6,
   *      min_val <= sorted_temp_readings[i]   
   */
  min_val = sorted_temp_readings[0];
  
  /* print minimum value to console */
  printf("%d\n", min_val);

  return 0;
}