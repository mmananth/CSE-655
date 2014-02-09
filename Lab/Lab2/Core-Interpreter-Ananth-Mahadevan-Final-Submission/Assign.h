#ifndef _ASSIGN_H_
#define _ASSIGN_H_
#include "Expression.h"
#include "ID.h"

class Assign:public Tokenizer
{
private:
  int curToken,resultAssign;
public:
  Assign(){};
  ID id;
  Expression exp;
  void parseAssign();
  void printAssign();
  void execAssign();
};

#endif 
