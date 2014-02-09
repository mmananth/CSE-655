/*************************************************************/
/*CSE655-Core-Interpreter				     */
/*Author: Ananth Mahadevan				     */
/*Description: Checks for comparison operators and calls the */
/*             appropriate function      		     */
/*************************************************************/
#include "Assign.h"

extern Tokenizer t;
int resultAssign=0;

void Assign::parseAssign()
{
  curToken=t.getToken();

#ifdef ENABLE_DEBUG_PARSE
  cout<<"curToken in parseAssign-1 "<<curToken<<endl;
#endif
  //Check if current Token is an Identifier, Integer, =, +, - or ;
  //and call appropriate function
  if(curToken == 32) { exp.parseExpression(); }
  else if(curToken == 31) { exp.parseExpression(); }
  else if(curToken == 14) { t.skipToken(); parseAssign(); }
  else if(curToken == 22) { t.skipToken(); parseAssign(); }
  else if(curToken == 23) { t.skipToken(); parseAssign(); }
  else if(curToken == 12) { t.skipToken(); }
  else { cout<<"Error-while parsing "<<endl; exit(1); }
}

void Assign::printAssign()
{
  exp.printExpression();
}

void Assign::execAssign()
{
  resultAssign=exp.execExpression();
  id.setIDVal(resultAssign);
}
