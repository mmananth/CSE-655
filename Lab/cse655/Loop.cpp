#include "Loop.h"

extern Tokenizer t;

void Loop::parseLoop()
{
  checkWhile=checkWhileEnd=0;
  curToken=t.getToken();
  while(curToken != 3)
  {
    t.skipToken();
    curToken=t.getToken();

    if(curToken == 5) { cout<<" good-parseLoop "<<curToken<<endl; checkWhile++; }
    else if(curToken == 3) { cout<<" good-parseWhile-End "<<curToken<<endl; checkWhileEnd++; }
    cout<<"checkWhile count"<<checkWhile<<endl;
    cout<<"checkWhileEnd count"<<checkWhileEnd<<endl;
  }
}

void Loop::printLoop()
{
}

void Loop::execLoop()
{
}
