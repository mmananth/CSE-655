#ifndef _LOOP_H_
#define _LOOP_H_
#include "Condition.h"
#include "StmtSeq.h"

class StmtSeq;
class Condition;
class Loop:public Tokenizer
{
private:
  int curToken;
  bool checkCond;
public:
  Loop(){ ss=NULL; cond=NULL; };
  ~Loop();
  StmtSeq *ss;
  Condition *cond;
  void parseLoop();
  void printLoop();
  void execLoop();
  Condition* getCondInstanceLoop();
  StmtSeq* getSSInstanceLoop();
};

#endif 
