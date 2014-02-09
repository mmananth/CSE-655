#include "StmtSeq.h"

extern Tokenizer t;

void StmtSeq::parseSS()
{
  int curToken=t.getToken();
  stmt.parseStmt();
  if(curToken == 5 || curToken == 8 || curToken == 10 || curToken == 11) 
  {
    parseSS();
  }
}

void StmtSeq::printSS()
{
}

void StmtSeq::execSS()
{
}
