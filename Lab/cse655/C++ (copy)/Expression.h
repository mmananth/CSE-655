#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include "Trm.h"

class Expression:public Tokenizer
{
public:
  Expression(){};
  Trm trm;
  int curToken;
  int altNum;
  void parseExpression();
  void printExpression();
  int execExpression();
};

#endif 
