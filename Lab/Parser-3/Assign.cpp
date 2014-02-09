#include "Assign.h"

extern Tokenizer t;

int resultAssign=0;
void Assign::parseAssign()
{
  curToken=t.getToken();
  //id=ID->parseIDForSS();

  if(curToken != 14) { cout<<"Error-expecting = "<<endl; exit(1); }
  t.skipToken();
  exp.parseExpression(); 

  if(curToken != 12) { cout<<"Error-expecting ; "<<endl; exit(1); }
  t.skipToken();
  //id=ID->parseIDForSS();
}

void Assign::printAssign()
{
  //cout<<id.getName();
  exp.printExpression();
  cout<<" ; ";
}

void Assign::execAssign()
{
  resultAssign=exp.execExpression();
  id.setIDVal(resultAssign);
}
