#ifndef _STATEMENTSEQ_H
#define _STATEMENTSEQ_H
#include "Stmt.h"

class Stmt;
class StmtSeq:public Tokenizer
{
private:
  int curToken;
public:
  Stmt *stmt;
  StmtSeq(){ stmt=NULL; };
  void parseSS();
  void printSS();
  void execSS();
  Stmt* getStmtInstanceSS();
  ~StmtSeq();
};

#endif 
