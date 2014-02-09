#ifndef _COMPARE_H_
#define _COMPARE_H_
#include "Tokenizer.h"
#include "CompareOperator.h"
#include "Operator1.h"


class Compare:public Tokenizer
{
public:
  Compare(){};
  CompareOperator compOp;
  Operator1 op;
  int curToken;
  void parseCompare();
  void printCompare();
  void execCompare();
};

#endif 
