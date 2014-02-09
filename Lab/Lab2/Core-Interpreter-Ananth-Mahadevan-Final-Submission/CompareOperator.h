#ifndef _COMPAREOPERATOR_H_
#define _COMPAREOPERATOR_H_
#include "Tokenizer.h"

class CompareOperator:public Tokenizer
{
private:
  int curToken, altNum;
public:
  CompareOperator(){};
  void parseCompareOperator();
  void printCompareOperator();
  void execCompareOperator();
};

#endif 
