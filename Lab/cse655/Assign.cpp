#include "Assign.h"

extern Tokenizer t;

void Assign::parseAssign()
{
  curToken=t.getToken();
  if(curToken == 32) { cout<<" good-parseAssign-1 "<<curToken<<endl; }
  else if(curToken == 14) { cout<<" good-parseAssign-2 "<<curToken<<endl; }
  exp.parseExpression(); 
  //id.parseIDForSS();
}

void Assign::printAssign()
{
  id.printID();
}

void Assign::execAssign()
{
}
