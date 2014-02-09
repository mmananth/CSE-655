#ifndef _IF_H_
#define _IF_H_
#include "Tokenizer.h"
#include "Condition.h"
#include "StmtSeq.h"

class Condition;
class StmtSeq;
class IF:public Tokenizer
{
private:
  int curToken;
  bool valueIfBool;
public:
  IF(){ ss=NULL; cond=NULL; };
  ~IF();
  Condition *cond;
  StmtSeq *ss;
  void parseIF();
  void printIF();
  void execIF();
  Condition* getCondInstance();
  StmtSeq* getSSInstance();
};

#endif 
