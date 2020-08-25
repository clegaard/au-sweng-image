/*
 * Check if a specific value is in an array
 */

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <stdbool.h> /* bool, true, false */

#define DAY_COUNT 6

int main(void)
{
  int temp_readings[DAY_COUNT] = {32, 18, 16, 28, 35, 9};
    /* the temperature readings */
  int check_value = 28;
    /* check if this value is in the array */
  bool has_value;
    /* TRUE if check_value is in temp_readings */
  int next_val; /* next temperature value in the array */
  int i;        /* counter variable */

  /* pre-condition */
  /* true */

  /* post-condition */
  /* has_value == (exists i such that 0 <= i < DAY_COUNT
   *      temp_readings[i] == check_value)
   */
  has_value = false;
  for(i = 0; i < DAY_COUNT; i = i + 1)
  {
    /* invariant:
     *  has_value == (exists k such that 0 <= k <= i
     *      temp_readings[k] == check_value)
     */
     next_val = temp_readings[i];
     if(next_val == check_value)
     {
       has_value = true;
       break;
     }
  }
  
  if(has_value)
    printf("Temperature readings HAS checked value\n");
  else
    printf("Temperature readings DOES NOT HAVE checked value\n");

  return 0;
}