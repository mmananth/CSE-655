#ifndef _COMPAREOPERATOR_H_
#define _COMPAREOPERATOR_H_
#include "Tokenizer.h"

class CompareOperator:public Tokenizer
{
public:
  CompareOperator() {};
  int curToken;
  void parseCompareOperator();
  void printCompareOperator();
  void execCompareOperator();
};

#endif 
