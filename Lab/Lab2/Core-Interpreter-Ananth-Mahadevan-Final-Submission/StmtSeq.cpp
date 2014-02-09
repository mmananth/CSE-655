/*************************************************************/
/*CSE655-Core-Interpreter                                    */
/*Author: Ananth Mahadevan                                   */
/*Description: Calls the Stmt.cpp file for processing the    */
/* the statements					     */
/*************************************************************/
#include "StmtSeq.h"

extern Tokenizer t;

StmtSeq::~StmtSeq()
{
  delete stmt;
}

void StmtSeq::parseSS()
{
  stmt=new Stmt();
  curToken=t.getToken();
#ifdef ENABLE_DEBUG_PARSE
  cout<<"curToken in parseSS "<<curToken<<endl;
#endif
  this->getStmtInstanceSS()->parseStmt();
  curToken=t.getToken();
  if( (curToken == 32) || (curToken == 5) || (curToken == 8) || (curToken == 10) || (curToken == 11) )
  {
    parseSS();
  }
}

void StmtSeq::printSS()
{
  curToken=t.getToken();
  if( (curToken == 32) || (curToken == 5) || (curToken == 8) || (curToken == 10) || (curToken == 11) )
  {
#ifdef ENABLE_DEBUG_PRINT
    cout<<" curToken - printSS "<<curToken<<endl;
#endif
    this->getStmtInstanceSS()->printStmt();
  }
}

void StmtSeq::execSS()
{
  this->getStmtInstanceSS()->execStmt();
}

Stmt* StmtSeq::getStmtInstanceSS()
{
  if(stmt==NULL)
    return new Stmt();
  else
    return stmt;
}
