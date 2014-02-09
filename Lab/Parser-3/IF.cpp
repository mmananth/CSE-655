#include "IF.h"

extern Tokenizer t;

IF::~IF()
{
  delete cond;
  delete ss;
}

void IF::parseIF()
{
  curToken=t.getToken();
  if(curToken != 5)
  {
    cout<<"Error-expecting if"<<endl;
    exit(0);
  }
  t.skipToken();
  cond->parseCondition();

  curToken=t.getToken();
  if(curToken != 6) {
    cout<<"Error-expecting then"<<endl;
    exit(0);
  }
  t.skipToken();
  ss->parseSS();

  curToken=t.getToken();
  if(curToken==7) {
    t.skipToken();
    ss->parseSS();
  }

  curToken=t.getToken();
  if(curToken!=3){
    cout<<"Error-expecting end"<<endl;
    exit(0);
  }
  t.skipToken();
  curToken=t.getToken();
  if(curToken!=12) {
    cout<<"Error-expecting ;"<<endl;
    exit(0);
  }
  t.skipToken();
}

void IF::printIF()
{
  cout<<" If ";
  cond->printCondition();
  cout<<" then ";
  ss->printSS();
  cout<<" end ";
}

void IF::execIF()
{
  valueIfBool=cond->execCondition();
  if(valueIfBool==true){
    ss->execSS();
  }
}
