#ifndef _ASSIGN_H_
#define _ASSIGN_H_
#include "Expression1.h"
#include "ID.h"

class Assign:public Tokenizer
{
public:
  Assign(){};
  int curToken,resultAssign;
  ID id;
  Expression1 exp;
  void parseAssign();
  void printAssign();
  void execAssign();
};

#endif 
