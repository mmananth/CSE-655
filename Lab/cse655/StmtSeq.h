#ifndef _STATEMENTSEQ_H
#define _STATEMENTSEQ_H
#include "Tokenizer.h"
#include "Stmt.h"

class StmtSeq:public Tokenizer
{
public:
  void parseSS();
  void printSS();
  void execSS();
  StmtSeq(){};
  Stmt stmt;
  //Tokenizer t;
};

#endif 
