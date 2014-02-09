#include "Condition.h"

extern Tokenizer t;

void Condition::parseCondition()
{
  cout<<"parseCondition.cpp "<<endl;
  //curToken=t.getToken();
  /*if( (curToken == 25) && (curToken == 26) && (curToken == 27) && (curToken == 28) && (curToken == 29) && (curToken == 30) ){
    cout<<"Compare is good"<<endl;*/
    comp.parseCompare();
  //}
}

void Condition::printCondition()
{
  comp.printCompare();
}

void Condition::execCondition()
{
  comp.execCompare();
}
