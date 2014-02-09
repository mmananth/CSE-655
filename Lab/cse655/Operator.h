#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include "Tokenizer.h"
#include "Number.h"
#include "ID.h"

class Operator:public Tokenizer
{
public:
  Operator() {};
  int curToken;
  Number numb;
  ID id;
  void parseOperator();
  void printOperator();
  void execOperator();
};

#endif 
