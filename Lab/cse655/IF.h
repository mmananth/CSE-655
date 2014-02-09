#ifndef _IF_H_
#define _IF_H_
#include "Tokenizer.h"
#include "Condition.h"

class IF:public Tokenizer
{
public:
  IF(){};
  Condition cond;
  int checkIfEnd, checkIf;
  int curToken;
  void parseIF();
  void printIF();
  void execIF();
};

#endif 
