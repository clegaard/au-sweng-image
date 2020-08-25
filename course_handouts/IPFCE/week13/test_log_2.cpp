/*
 * Test log class:
 * Log results of an arithmetic operation
 */

#include "log.h"
#include <stdio.h>
#include <stdbool.h>

/* evaluates expression, returns true on 
 * success and false on failure
 */
bool evaluate(int x, char op, int y, int &res)
{
  /* perform calculation */
  switch(op)
  {
    case '+':
      res = x + y;
      break;
    case '-':
      res = x - y;
      break;
    case '*':
      res = x * y;
      break;
    case '/':
      if(y == 0)
        return false;
      res = x / y;
      break;
    default:
      return false;
  }
  return true;
}

int main(void)
{

  int x;   /* integer inputs from user */
  int y;   
  char op; /* operation given by user */
  int res; /* res = x op y */
  bool succ; /* success flag */

  const int n = 20; /* max equation string length */
  char equation[n]; /* equation as a string for logging */

  /* start logger */
  Log lg("Arithmetic_Logger.txt");
  lg.write_message("Taking user inputs...");

  /* get user input */
  scanf("%d", &x);
  scanf("%d", &y);
  scanf(" %c", &op);

  lg.write_message("User input complete");
  lg.write_message("Computing arithmetic operation");
  
  /* perform evaluation */
  succ = evaluate(x, op, y, res);
  if(!succ)
    return 1; /* exit with error */

  /* log results */
  snprintf(equation, n, "%d %c %d = %d", x, op, y, res);
  lg.write_message(equation);

  return 0;
}