#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include "Tokenizer.h"
#include "Trm.h"

class Expression:public Tokenizer
{
public:
  Expression() {};
  int curToken;
  Trm trm;
  void parseExpression();
  void printExpression();
  void execExpression();
};

#endif 
