#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include "Expression.h"

class Operator:public Tokenizer
{
public:
  Operator(){};
  ID id;
  Expression exp;
  int curToken,no,altNum;
  void parseOperator();
  void printOperator();
  int execOperator();
};

#endif 
