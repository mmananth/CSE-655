#ifndef _COMPARE_H_
#define _COMPARE_H_
#include "Tokenizer.h"
#include "CompareOperator.h"
#include "Operator.h"

class Compare:public Tokenizer
{
private:
  int curToken;
public:
  Compare(){};
  CompareOperator compOp;
  Operator op;
  void parseCompare();
  void printCompare();
  void execCompare();
};

#endif 
