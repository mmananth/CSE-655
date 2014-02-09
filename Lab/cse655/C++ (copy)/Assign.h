#ifndef _ASSIGN_H_
#define _ASSIGN_H_
#include "ID.h"

class Assign:public Tokenizer
{
public:
  Assign(){};
  int curToken,resultAssign;
  ID id;
  Expression exp;
  void parseAssign();
  void printAssign();
  void execAssign();
};

#endif 
