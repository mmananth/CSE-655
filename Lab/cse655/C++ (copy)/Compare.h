#ifndef _COMPARE_H_
#define _COMPARE_H_
#include "CompareOperator.h"
#include "Operator.h"

class Compare:public Tokenizer
{
public:
  Compare(){};
  CompareOperator compOp;
  Operator op;
  int curToken;
  void parseCompare();
  void printCompare();
  void execCompare();
};

#endif 
