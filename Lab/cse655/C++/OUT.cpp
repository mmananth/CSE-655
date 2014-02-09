#include "OUT.h"

extern Tokenizer t;

void OUT::parseOUT()
{
  curToken=t.getToken();
  if(curToken != 11){
    cout<<"Error-expecting write"<<endl;
    exit(0);
  }
  t.skipToken();
  idl->parseIDListForSS();
  curToken=t.getToken();
  if(curToken != 12) {
    cout<<"Error-expecting ;"<<endl;
    exit(0);
  }
  t.skipToken();
}

void OUT::printOUT()
{
  cout<<"write ";
  idl->printIDList();
  cout<<"; ";
}

void OUT::execOUT()
{
  idl->writeOutput();
}
