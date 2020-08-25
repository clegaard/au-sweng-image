/*
 * Log Class to record timestamped
 * messages
 */

#include "log.h"
#include <assert.h> /* assert */
#include <time.h>   /* time_t, time, ctime */

Log::Log(const char* fn)
{
  /* post-condition*/

  /* open file for writing */
  file_ = fopen(fn, "w");

  assert (file_ != NULL);
}

Log::~Log()
{
  if(file_ != NULL)
  {
   /* end of log message */
   write_message("END OF LOG");

   /* close file */
   fclose(file_);
  }
}

/* Returns current time as a string
 * Important: return string is static,
 * i.e. not created using malloc/calloc
 * so don't try to free it later, see:
 *   man ctime
 */
char* Log::current_time()
{
  time_t now;     /* current time */
  char * time_str;
    /* current time represented as a string */

  now = time(0);
  time_str = ctime(&now);

  return time_str;
}

void Log::write_message(const char* msg)
{
  /* pre-condition */
  assert (file_ != NULL);

  /* post-condition */
  char* tm = current_time();
  fprintf(file_, "[TIMESTAMP]:%s[MESSAGE]  :%s\n", tm, msg);
}
