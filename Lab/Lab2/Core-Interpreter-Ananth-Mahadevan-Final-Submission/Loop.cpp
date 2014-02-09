/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for processing the While loop and its 	*/
/* associated conditions					*/
/****************************************************************/
#include "Loop.h"

extern Tokenizer t;

Loop::~Loop()
{
  delete cond;
  delete ss;
}

void Loop::parseLoop()
{
  curToken=t.getToken();
  if(curToken == 8)
  {
    t.skipToken();
    this->getCondInstanceLoop()->parseCondition();
  }
  else {
    cout<<"Error-expecting while"<<endl;
    exit(0);
  }
  curToken=t.getToken();
  if(curToken == 9){
    t.skipToken();
    this->getSSInstanceLoop()->parseSS();
  }
  else {
    cout<<"Error-expecting loop"<<endl;
    exit(0);
  }

  curToken=t.getToken();
  if(curToken == 3) {
    t.skipToken();
  }
  else {
    cout<<"Error-expecting End"<<endl;
    exit(0);
  }

  curToken=t.getToken();
  if(curToken == 12) {
    t.skipToken();
  }
  else{
    cout<<"Error-expecting ;"<<endl;
    exit(0);
  }
}

void Loop::printLoop()
{
  curToken=t.getToken();
  if( (curToken==20) || (curToken==15) || (curToken==16) ) { 
    this->getCondInstanceLoop()->printCondition(); 
    curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
    cout<<" curToken-printLoop "<<curToken<<endl;
#endif
    if(curToken==9) { cout<<" loop"<<endl; }
    else if(curToken==12) { cout<<" ;"<<endl; }
  }
  else { this->getSSInstanceLoop()->printSS(); }
}

void Loop::execLoop()
{
  checkCond=true;
  while(checkCond==true) {
    checkCond=this->getCondInstanceLoop()->execCondition();
    this->getSSInstanceLoop()->execSS();
  }
}

Condition* Loop::getCondInstanceLoop()
{
  if(cond==NULL)
    return new Condition();
  else
    return cond;
}

StmtSeq* Loop::getSSInstanceLoop()
{
  if(ss==NULL)
    return new StmtSeq();
  else
    return ss;
}
