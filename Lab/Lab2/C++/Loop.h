#ifndef _LOOP_H_
#define _LOOP_H_
#include "Condition.h"
#include "StmtSeq.h"

class StmtSeq;
class Condition;
class Loop:public Tokenizer
{
public:
  Loop(){ ss=NULL; cond=NULL; };
  ~Loop();
  StmtSeq *ss;
  Condition *cond;
  int curToken;
  bool checkCond;
  void parseLoop();
  void printLoop();
  void execLoop();
  Condition* getCondInstanceLoop();
  StmtSeq* getSSInstanceLoop();
};

#endif 
