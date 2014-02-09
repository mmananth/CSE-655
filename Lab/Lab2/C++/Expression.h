#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include "ConflictRes.h"

class Trm;
class Expression:public Tokenizer
{
public:
  Trm *trm;
  Expression(){ trm=NULL; };
  ~Expression();
  int curToken;
  int altNum;
  void parseExpression();
  void printExpression();
  int execExpression();
  Trm* getTrmInstance();
};

#endif 
