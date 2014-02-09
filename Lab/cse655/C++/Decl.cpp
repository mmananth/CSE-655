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
  idl.parseIDListForDS();

  curToken=t.getToken();
  if(curToken != 12)
  {
    cout<<"Error - expecting ;"<<endl; 
    exit(1);
  }
  t.skipToken();
}

void Decl::printDecl()
{
  idl.printIDList();
}

void Decl::execDecl()
{
}
