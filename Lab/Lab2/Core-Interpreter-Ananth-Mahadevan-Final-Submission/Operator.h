#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include "ID.h"
#include "ConflictRes.h"

class Expression;
class Operator:public Tokenizer
{
private:
  string no;
  int curToken,altNum;
public:
  Operator(){ no=""; exp=NULL; };
  ~Operator();
  ID id;
  Expression *exp;
  void parseOperator();
  void printOperator();
  int execOperator();
  Expression* getExpInstanceOp();  
};

#endif 
