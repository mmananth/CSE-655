#ifndef _CONDITION_H_
#define _CONDITION_H_
#include "Compare.h"

class Condition:public Tokenizer
{
private:
  int curToken, altNum;
public:
  Condition(){};
  Compare comp;
  void parseCondition();
  void printCondition();
  bool execCondition();
};

#endif 
