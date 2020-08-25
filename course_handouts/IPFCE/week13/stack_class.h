/*
 * stack data structure implemented
 * using integer array
 */

#ifndef _STACK_CLASS_H_
#define _STACK_CLASS_H_

#define STACKSIZE 10

class Stack
{
private:
  int top;
  int data[STACKSIZE - 1];

public:
  Stack();  
  ~Stack();

  /* Insert item x at the top of stack */
  void Push(int x);

  /* Return (and remove) top item of stack */
  int  Pop();

  /* Test whether stack can accept more pushes */
  bool Full();

  /* Test whether stack can accept more pops */
  bool Empty();
};

#endif

