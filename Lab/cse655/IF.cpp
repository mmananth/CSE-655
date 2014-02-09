#include "IF.h"

extern Tokenizer t;

void IF::parseIF()
{
  checkIfEnd=checkIf=0;
  curToken=t.getToken();
  while(curToken != 3)
  {
    t.skipToken();
    curToken=t.getToken();

    if(curToken == 5) { cout<<" good-parseIF "<<curToken<<endl; checkIf++; }
    else if(curToken == 3) { cout<<" good-parseIf-End "<<curToken<<endl; checkIfEnd++; }
    cout<<"checkIf count"<<checkIf<<endl;
    cout<<"checkIfEnd count"<<checkIfEnd<<endl;

    cond.parseCondition();
  }
}

void IF::printIF()
{
  cond.printCondition();
}

void IF::execIF()
{
  cond.execCondition();
}
