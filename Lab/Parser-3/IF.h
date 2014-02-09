#ifndef _IF_H_
#define _IF_H_
#include "Tokenizer.h"
#include "Condition.h"
#include "StmtSeq.h"

class Condition;
class StmtSeq;
class IF:public Tokenizer
{
public:
  IF(){};
  ~IF();
  Condition *cond;
  StmtSeq *ss;
  int curToken;
  bool valueIfBool;
  void parseIF();
  void printIF();
  void execIF();
};

#endif 
