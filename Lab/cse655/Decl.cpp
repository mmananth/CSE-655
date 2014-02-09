#include "Decl.h"

extern Tokenizer t;

void Decl::parseDecl()
{
  curToken=t.getToken();
  if(curToken != 4)
  {
    cout<<"Error - expecting int"<<endl; 
    exit(1);
  }
  t.skipToken();
  idl.parseIdListForDS();
}

void Decl::printDecl()
{
  idl.printIdList();
}

void Decl::execDecl()
{
}
