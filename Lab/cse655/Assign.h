#ifndef _ASSIGN_H_
#define _ASSIGN_H_
#include "Tokenizer.h"
#include "ID.h"
#include "Expression.h"

class Assign:public Tokenizer
{
public:
  Assign(){};
  int curToken;
  ID id;
  Expression exp;
  void parseAssign();
  void printAssign();
  void execAssign();
};

#endif 
