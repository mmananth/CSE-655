#ifndef _CONDITION_H_
#define _CONDITION_H_
#include "Tokenizer.h"
#include "Compare.h"

class Condition:public Tokenizer
{
public:
  Condition() {};
  int curToken();
  Compare comp;
  void parseCondition();
  void printCondition();
  void execCondition();
};

#endif 
