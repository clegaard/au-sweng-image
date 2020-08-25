/*
 * Test log class
 */

#include "log.h"

int main(void)
{
  const char* filename; /* log file name */
  const char* msg1;     /* messages to log */
  const char* msg2;     
  const char* msg3;     

  filename = "Test_Log.txt";
  msg1 = "Test message 1";
  msg2 = "Test message 2";
  msg3 = "Test message 3";

  /* create the Log instance 
   * and write messages to the 
   * log file
   */
  Log lg(filename);
  lg.write_message(msg1);
  lg.write_message(msg2);
  lg.write_message(msg3);

  return 0;
}