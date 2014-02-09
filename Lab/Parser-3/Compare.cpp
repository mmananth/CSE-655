#include "Compare.h"

extern Tokenizer t;

void Compare::parseCompare()
{
  curToken=t.getToken();
  if(curToken != 20)
  {
    cout<<"error in parseCompare-Compare.h"<<endl;
    exit(0);
  }
    t.skipToken();
    op.parseOperator();
    compOp.parseCompareOperator();
    op.parseOperator();
    curToken=t.getToken();
  if(curToken != 21)
  {
    cout<<"error in parseCompare-Compare.h"<<endl;
    exit(0);
  }
    t.skipToken();
}

void Compare::printCompare()
{
}

void Compare::execCompare()
{
}
