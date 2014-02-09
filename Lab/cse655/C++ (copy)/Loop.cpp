#include "Loop.h"

extern Tokenizer t;
//StmtSeq ss;

void Loop::parseLoop()
{
  curToken=t.getToken();
  if(curToken != 8)
  {
    cout<<"Error-expecting while"<<endl;
    exit(0);
  }
  t.skipToken();
  cond.parseCond();
  curToken=t.getToken();
  if(curToken != 9){
    cout<<"Error-expecting loop"<<endl;
    exit(0);
  }
  t.skipToken();
  ss.parseSS();

  curToken=t.getToken();
  if(curToken != 3) {
    cout<<"Error-expecting end"<<endl;
    exit(0);
  }
  t.skipToken();
  curToken=t.getToken();
  if(curToken != 12) {
    cout<<"Error-expecting ;"<<endl;
    exit(0);
  }
  t.skipToken();
}

void Loop::printLoop()
{
  cout<<"while ";
  cond.printCond();
  cout<<" loop";
  ss.printSS();
  cout<<" end";
}

void Loop::execLoop()
{
  checkCond=true;
  while(checkCond==true) {
    checkCond=cond.execCondition();
    ss.executeSS();
  }
}
