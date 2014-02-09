#ifndef _STATEMENTSEQ_H
#define _STATEMENTSEQ_H
#include "Stmt.h"

class StmtSeq:public Tokenizer
{
public:
  StmtSeq(){};
  Stmt stmt;
  void parseSS();
  void printSS();
  void execSS();
};

#endif 
