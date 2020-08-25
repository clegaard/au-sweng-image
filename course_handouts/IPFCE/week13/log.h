/*
 * stack data structure implemented
 * using integer array
 */

#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>  /* FILE, fprintf, fopen, fclose */

class Log
{
private:
  FILE* file_; /* log text file to write to */

  /* get current time as string */
  char* current_time();

public:
  Log(const char* fn);
  ~Log();

  /* write timestamped message to log file */
  void write_message(const char* msg);

};

#endif

