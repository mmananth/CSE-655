/*************************************************************/
/*CSE655-Core-Interpreter				     */
/*Author: Ananth Mahadevan				     */
/*Description: Checks if the comparison operators used are   */
/*             legal or not (!=, ==, < , >, <=, >=)          */
/*************************************************************/
#include "CompareOperator.h"

extern Tokenizer t;

void CompareOperator::parseCompareOperator()
{
  curToken=t.getToken();
  //Check if token is one of the Comparison operators
  if(curToken == 25) { altNum=1; }
  else if(curToken == 26) { altNum=2; }
  else if(curToken == 27) { altNum=3; }
  else if(curToken == 28) { altNum=4; }
  else if(curToken == 29) { altNum=5; }
  else if(curToken == 30) { altNum=6; }
  else { cout<<"Error-Unexpected Comparison Operators"<<endl; }
  t.skipToken();
}

void CompareOperator::printCompareOperator()
{
  curToken=t.getToken();
  if(curToken == 25) { cout<<" != "; }
  else if(curToken == 26) { cout<<" == "; }
  else if(curToken == 27) { cout<<" < "; }
  else if(curToken == 28) { cout<<" > "; }
  else if(curToken == 29) { cout<<" <= "; }
  else if(curToken == 30) { cout<<" >= "; }
  else { cout<<"Error-Unexpected Comparison Operators"<<endl; }
}

void CompareOperator::execCompareOperator()
{
}
