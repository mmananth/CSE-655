#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include "ID.h"
#include "ConflictRes.h"

class Expression;
class Operator:public Tokenizer
{
public:
  string no;
  Operator(){ no=""; exp=NULL; };
  ~Operator();
  ID id;
  Expression *exp;
  int curToken,altNum;
  void parseOperator();
  void printOperator();
  int execOperator();
  Expression* getExpInstanceOp();  
};

#endif 
