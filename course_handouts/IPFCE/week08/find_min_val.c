/*
 * Find minimum value in an array of unsorted integers
 */

#include <stdio.h>  /* printf */
#include <assert.h> /* assert */

#define DAY_COUNT 6

int main(void)
{
  int temp_readings[DAY_COUNT] = {32, 18, 16, 28, 35, 9};
    /* the temperature readings */
  int curr_min; /* minimum temperature found so far */
  int next_val; /* next temperature value in the array */
  int i;        /* counter variable */
  

  /* pre-condition */
  /* at least 1 temperature reading in the array */
  assert (1 <= DAY_COUNT);

  /* post-condition */
  /* for all i such that 0 <= i < 6,
   *      curr_min <= temp_readings[i]   
   */
  curr_min = temp_readings[0];
  for(i = 1; i < DAY_COUNT; i = i + 1)
  {
    /* invariant: for all k such that 0 <= k <= i,
     *               curr_min <= temp_readings[k]
     */
     next_val = temp_readings[i];
     if(next_val < curr_min)
       curr_min = next_val;
  }
  
  /* print minimum value to console */
  printf("%d\n", curr_min);

  return 0;
}