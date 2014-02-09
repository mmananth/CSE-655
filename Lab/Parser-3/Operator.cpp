#include "Operator.h"

extern Tokenizer t;
//Expression exp;

void Operator::parseOperator()
{
  curToken=t.getToken();
  if(curToken==31){
    altNum=1;
    no=t.intVal();
    t.skipToken();
  } 
  else if(curToken==32){
    altNum=2;
    id.parseIDForSS();
  }
  else if(curToken==20) {
    altNum=3;
    t.skipToken();
    exp->parseExpression();
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
  if(altNum==1) {
    cout<<no;
  } else if(altNum==2) {
      cout<<id.getIDName();
  } else {
	cout<<"(";
	exp->printExpression();
	cout<<")";
    }
}

int Operator::execOperator()
{
  if(altNum==1){
    cout<<no;
  } else if(altNum==2) {
      //if(!id.getInitialized()){
	//cout<<"Run time error"<<id.getIDName<<" has not been initialized"<<endl;
    	//exit(0);
      //}
      return id.getIDVal();
  } else {
	return exp->execExpression();
    }
}
