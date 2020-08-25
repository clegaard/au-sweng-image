/*
 * Check if a specific value is in a sorted array
 * using binary search
 */

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <stdbool.h> /* bool, true, false */

#define DAY_COUNT 6

int main(void)
{
  int sorted_temp_readings[DAY_COUNT] = {9, 16, 18, 28, 32, 35};
    /* the temperature readings in ascending order */
  int check_value = 28;
    /* check if this value is in the array */
  bool has_value;
    /* TRUE if check_value is in temp_readings */
  int low;      /* lower index in search interval */
  int high;     /* upper index in search interval */
  int mid;      /* middle index of the search interval */
  int low_val;  /* value at low index in search interval */
  int high_val; /* value at high index in search interval */ 
  int mid_val;  /* value at mid index in search interval */ 

  /* pre-condition */
  /* true */

  /* post-condition */
  /* has_value == (exists i such that 0 <= i < DAY_COUNT
   *      sorted_temp_readings[i] == check_value)
   */
  low = 0;
  high = DAY_COUNT - 1;
  has_value = false;
  while(low <= high)
  {
    /* invariant:
     *  for all k1,k2 such that k1 < low and high < k2
     *        sorted_temp_readings[k1] != check_value
     *    and sorted_temp_readings[k2] != check_value)
     */

    low_val  = sorted_temp_readings[low];
    high_val = sorted_temp_readings[high];

    /* terminate condition: check value found */
    if(   check_value == low_val
       || check_value == high_val)
    {
      has_value = true;
      break;
    }

    /* terminate condition:
     * check value out of bounds of search interval
     */
    if(   check_value < low_val
       || check_value > high_val)
    {
      has_value = false;
      break;
    }

    /* case: check value within search interval bounds
     * update search interval bounds
     */ 
    mid = (high - low) / 2;
    mid_val = sorted_temp_readings[mid];

    if(check_value < mid_val)
    { /* search lower half of remaining interval */
      low = low + 1;
      high = mid;
    } else
    { /* search upper half of remaining interval */
      high = high - 1;
      low = mid;
    }

  }
  
  if(has_value)
    printf("Temperature readings HAS checked value\n");
  else
    printf("Temperature readings DOES NOT HAVE checked value\n");

  return 0;
}