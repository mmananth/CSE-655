#include "StmtSeq.h"

extern Tokenizer t;
//Stmt stmt;

void StmtSeq::parseSS()
{
  int curToken=t.getToken();
  stmt.parseStmt();
  if( (curToken == 32) || (curToken == 5) || (curToken == 8) || (curToken == 10) || (curToken == 11) )
  {
    parseSS();
  }
}

void StmtSeq::printSS()
{
  stmt.printStmt();
}

void StmtSeq::execSS()
{
  stmt.execStmt();
}
