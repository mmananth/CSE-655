#ifndef _STATEMENT_H_
#define _STATEMENT_H_
#include "OUT.h"
#include "IN.h"
#include "IF.h"
#include "Assign.h"
#include "Loop.h"

class Stmt:public Tokenizer
{
private:
  int altNum;
public:
  Stmt(){};
  int curToken;
  OUT out;
  IN in;
  IF pif;
  Assign assign;
  Loop loop;
  void parseStmt();
  void printStmt();
  void execStmt();
};

#endif 
