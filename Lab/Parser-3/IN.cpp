#include "IN.h"

extern Tokenizer t;

void IN::parseIN()
{
  curToken=t.getToken();
  if(curToken != 10){
    cout<<"Error-expecting read"<<endl;
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

void IN::printIN()
{
  cout<<"read";
  idl->printIDList();
  cout<<";";
}

void IN::execIN()
{
  idl->readInput();
}
