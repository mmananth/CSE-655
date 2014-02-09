#ifndef _OPERATOR1_H_
#define _OPERATOR1_H_
#include "ID.h"
#include "ConflictRes.h"

class Expression1;
class Operator1:public Tokenizer
{
public:
  Operator1(){};
  ID id;
  Expression1 *exp;
  int curToken,no,altNum;
  void parseOperator();
  void printOperator();
  int execOperator();
};

#endif 
