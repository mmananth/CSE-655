#include "Compare.h"

extern Tokenizer t;

void Compare::parseCompare()
{
  curToken=t.getToken();
  if( (curToken == 20) && (curToken == 21) )
  {
    op.parseOperator();
    compOp.parseCompareOperator();
    //op.parseOperator();
  }
  else
    cout<<"error in parseCompare-Compare.h"<<endl;
}

void Compare::printCompare()
{
}

void Compare::execCompare()
{
}
