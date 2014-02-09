#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include "ConflictRes.h"

class Trm;
class Expression:public Tokenizer
{
private:
  int curToken, altNum;
public:
  Trm *trm;
  Expression(){ trm=NULL; };
  ~Expression();
  void parseExpression();
  void printExpression();
  int execExpression();
  Trm* getTrmInstance();
};

#endif 
