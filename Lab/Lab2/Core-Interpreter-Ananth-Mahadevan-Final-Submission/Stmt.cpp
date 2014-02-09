/*************************************************************/
/*CSE655-Core-Interpreter                                    */
/*Author: Ananth Mahadevan                                   */
/*Description: For processing the statements after the "begin"*/
/* keyword						     */
/*************************************************************/
#include "Stmt.h"

extern Tokenizer t;

Stmt::~Stmt()
{
  delete pif;
  delete loop;
}

void Stmt::parseStmt()
{
  curToken=t.getToken();     
#ifdef ENABLE_DEBUG_PRINT
  cout<<"curToken in parseStmt "<<curToken<<endl;
#endif
 
  if(curToken == 32)
  {
    altNum=1;
    t.skipToken();
#ifdef ENABLE_DEBUG_PRINT
    cout<<"calling parseAssign"<<endl;
#endif
    assign.parseAssign();
  }

  else if(curToken == 5)
  {
    altNum=2;
#ifdef ENABLE_DEBUG_PRINT
    cout<<"calling parseIF"<<endl;
#endif
    this->getIfInstanceStmt()->parseIF();
  }

  else if(curToken == 8)
  {
    altNum=3;
#ifdef ENABLE_DEBUG_PRINT
    cout<<"calling parseLoop"<<endl;
#endif
    this->getLoopInstanceStmt()->parseLoop();
  }

  else if(curToken == 10)
  {
    altNum=4;
#ifdef ENABLE_DEBUG_PRINT
    cout<<"calling parseIN"<<endl;
#endif
    in.parseIN();
  }

  else if(curToken == 11)
  {
#ifdef ENABLE_DEBUG_PRINT
    cout<<"curToken-before calling OUT "<<curToken<<endl;
#endif
    altNum=5;
    out.parseOUT();
  }
}

void Stmt::printStmt()
{
  curToken=t.getToken();
  if(curToken == 32){
    cout<<t.getIdName();
    t.skipToken();
    curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
    cout<<" curToken-printStmt- Var "<<curToken<<endl;
#endif
    assign.printAssign();
  }
  else if(curToken==5) {
    cout<<" if ";
    t.skipToken();
    cond.printCondition();
    curToken=t.getToken();
    while(curToken != 3) {
      this->getIfInstanceStmt()->printIF();
      t.skipToken();
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printStmt- if "<<curToken<<endl;
#endif
      if(curToken == 6){ cout<<" then "<<endl; t.skipToken(); }
      else if(curToken == 3) { cout<<" end "; }
      else if(curToken == 12) { cout<<" ; "<<endl; }
    }
  }
  else if(curToken==8) {
    cout<<" while ";
    t.skipToken();
    curToken=t.getToken();
    while(curToken != 3){
      this->getLoopInstanceStmt()->printLoop();
      t.skipToken();
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printStmt- while "<<curToken<<endl;
#endif
      if(curToken == 9){ cout<<" loop "<<endl; t.skipToken(); }
      else if(curToken == 3) { cout<<" end "; }
      else if(curToken == 12) { cout<<" ; "<<endl; }
    }
  }
  else if(curToken==10) {
    cout<<" read ";
    t.skipToken();
    curToken=t.getToken();
    while(curToken != 12){
      in.printIN();
      t.skipToken();
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printStmt- read "<<curToken<<endl;
#endif
      if(curToken==12) { cout<<"; "<<endl; }
      else if(curToken==13) { cout<<", "; }
      else if(curToken==14) { cout<<" = "; }
    }
  }
  else if(curToken==11) {
    cout<<" write ";
    t.skipToken();
    curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
    cout<<" curToken-printStmt- write "<<curToken<<endl;
#endif
    out.printOUT();
  }
}

void Stmt::execStmt()
{
  if(altNum==1) {
    assign.execAssign();
  }
  if(altNum==2) {
    this->getIfInstanceStmt()->execIF();
  }
  if(altNum==3) {
    this->getLoopInstanceStmt()->execLoop();
  }
  if(altNum==4) {
    in.execIN();
  }
  if(altNum==5) {
    out.execOUT();
  }
}

IF* Stmt::getIfInstanceStmt()
{
  if(pif==NULL)
    return new IF();
  else
    return pif;
}

Loop* Stmt::getLoopInstanceStmt()
{
  if(loop==NULL)
    return new Loop();
  else
    return loop;
}
