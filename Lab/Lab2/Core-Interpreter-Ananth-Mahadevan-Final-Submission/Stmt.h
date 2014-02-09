#ifndef _STATEMENT_H_
#define _STATEMENT_H_
#include "OUT.h"
#include "IN.h"
#include "IF.h"
#include "Assign.h"
#include "Loop.h"
#include "Condition.h"

class IF;
class Loop;
class Stmt:public Tokenizer
{
private:
  int curToken, altNum;
public:
  IF *pif;
  Loop *loop;
  Stmt(){ pif=NULL; loop=NULL; };
  ~Stmt();
  OUT out;
  IN in;
  Assign assign;
  Condition cond;
  void parseStmt();
  void printStmt();
  void execStmt();
  IF* getIfInstanceStmt();
  Loop* getLoopInstanceStmt();
};

#endif 
