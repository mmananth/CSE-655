#ifndef _STATEMENTSEQ_H
#define _STATEMENTSEQ_H
#include "Stmt.h"

class Stmt;
class StmtSeq:public Tokenizer
{
public:
  Stmt *stmt;
  StmtSeq(){ stmt=NULL; };
  int curToken;
  void parseSS();
  void printSS();
  void execSS();
  Stmt* getStmtInstanceSS();
  ~StmtSeq();
};

#endif 
