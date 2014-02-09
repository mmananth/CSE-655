#ifndef _EXPRESSION1_H_
#define _EXPRESSION1_H_
#include "ConflictRes.h"

class Trm;
class Expression1:public Tokenizer
{
public:
  Expression1(){};
  Trm *trm;
  int curToken;
  int altNum;
  void parseExpression();
  void printExpression();
  int execExpression();
};

#endif 
