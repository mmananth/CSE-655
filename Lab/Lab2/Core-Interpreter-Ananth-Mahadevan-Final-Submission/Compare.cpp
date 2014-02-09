/*************************************************************/
/*CSE655-Core-Interpreter				     */
/*Author: Ananth Mahadevan				     */
/*Description: Compares 2 variables using operators such as  */
/*             !=, ==, < , >, <=, >=			     */
/*************************************************************/
#include "Compare.h"

extern Tokenizer t;

void Compare::parseCompare()
{
  curToken=t.getToken();
  //check if current Token is (, which signals the start of an operator
  if(curToken == 20)
  {
    t.skipToken();
#ifdef ENABLE_DEBUG_PARSE
    cout<<"Compare-calling parseOperator 1"<<endl;
#endif
    op.parseOperator();
    t.skipToken();
    compOp.parseCompareOperator();
    t.skipToken();
    op.parseOperator();
  }
  else{
    cout<<"error in parseCompare-Compare.h"<<endl;
    exit(0);
  }

  curToken=t.getToken();
  //skip the Token if it is a )
  if(curToken == 21)
  {
    t.skipToken();
  }
  else{
    cout<<"error in parseCompare-Compare.h"<<endl;
    exit(0);
  }
}

void Compare::printCompare()
{
  op.printOperator();
  t.skipToken();
  compOp.printCompareOperator();
  t.skipToken();
  op.printOperator();
  t.skipToken();
  curToken=t.getToken();
  if(curToken==21) { cout<<" ) "; t.skipToken(); }
  curToken=t.getToken();
  if(curToken==6) { cout<<" then"<<endl; t.skipToken(); }
}

void Compare::execCompare()
{
}
