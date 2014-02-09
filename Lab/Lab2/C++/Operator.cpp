/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for processing mathematical operations	*/
/****************************************************************/
#include "Operator.h"

extern Tokenizer t;
//Expression exp;

Operator::~Operator()
{
  delete exp;
}

void Operator::parseOperator()
{
  curToken=t.getToken();
#ifdef ENABLE_DEBUG_PARSE
  cout<<"curToken in parseOperator "<<curToken<<endl;
#endif
  if(curToken==31){
    altNum=1;
  } 
  else if(curToken==32){
    altNum=2;
    id.parseIDForSS();
  }
  else if(curToken==20) {
    altNum=3;
    t.skipToken();
    this->getExpInstanceOp()->parseExpression();
    curToken=t.getToken();
    if(curToken != 21){
      cout<<"Error-expecting )"<<endl;
      exit(0);
    }
    t.skipToken();
  } 
}

void Operator::printOperator()
{
  curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
  cout<<" curToken-printOperator "<<curToken<<endl;
#endif
  if(curToken==31){
    no=t.intVal();
    cout<<no;
  } 
  else if(curToken==32) { cout<<t.getIdName(); } 
  else if(curToken==20) { 
    cout<<" ( "; 
    t.skipToken(); 
    this->getExpInstanceOp()->printExpression();
  }
  else if(curToken==21) { cout<<" ) "; t.skipToken(); }
}

int Operator::execOperator()
{
  if(altNum==1){
    no=t.intVal();
    cout<<no;
  } else if(altNum==2) {
      return id.getIDVal();
  } else {
	return this->getExpInstanceOp()->execExpression();
    }
}

Expression* Operator::getExpInstanceOp()
{
  if(exp==NULL)
    return new Expression();
  else 
    return exp;
}
