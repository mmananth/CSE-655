#ifndef _LOOP_H_
#define _LOOP_H_
#include "Condition.h"

class Loop:public Tokenizer
{
public:
  Loop() {};
  StmtSeq ss;
  Condition cond;
  int curToken;
  bool checkCond;
  void parseLoop();
  void printLoop();
  void execLoop();
};

#endif 
