/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for processing the IF loop and its associated*/
/* statments							*/
/****************************************************************/
#include "IF.h"

extern Tokenizer t;

IF::~IF()
{
  delete cond;
  delete ss;
}

void IF::parseIF()
{
  curToken=t.getToken();
  if(curToken != 5)
  {
    cout<<"Error-expecting if"<<endl;
    exit(0);
  }
  t.skipToken();
  this->getCondInstance()->parseCondition();

  curToken=t.getToken();
  if(curToken != 6) {
    cout<<"Error-expecting then"<<endl;
    exit(0);
  }
  t.skipToken();
  this->getSSInstance()->parseSS();

  curToken=t.getToken();
  if(curToken==7) {
    t.skipToken();
    this->getSSInstance()->parseSS();
  }

  curToken=t.getToken();
  if(curToken!=3){
    cout<<"Error-expecting end"<<endl;
    exit(0);
  }
  t.skipToken();
  curToken=t.getToken();
  if(curToken!=12) {
    cout<<"Error-expecting ;"<<endl;
    exit(0);
  }
  t.skipToken();
}

void IF::printIF()
{
  curToken=t.getToken();
  if( (curToken==20) || (curToken==15) || (curToken==16) ){ 
    this->getCondInstance()->printCondition(); 
    curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
    cout<<"curToken -printIF "<<curToken<<endl;
#endif
    if(curToken==6) { cout<<" then"<<endl; }
  }
  else if(curToken==7) { cout<<" else "<<endl; }
  else { this->getSSInstance()->printSS(); }
}

void IF::execIF()
{
  valueIfBool=this->getCondInstance()->execCondition();
  if(valueIfBool==true){
    this->getSSInstance()->execSS();
  }
}

Condition* IF::getCondInstance()
{
  if(cond==NULL)
    return new Condition();
  else
    return cond;
}

StmtSeq* IF::getSSInstance()
{
  if(ss==NULL)
    return new StmtSeq();
  else
    return ss;
}
