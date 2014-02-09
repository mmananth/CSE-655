/************************************************************************/
/*CSE655-Core-Interpreter				     		*/
/*Author: Ananth Mahadevan				     		*/
/*Description: Checks if the first character passed is "int" and processes*/ 
/*the rest of the ID values						*/
/************************************************************************/
#include "Decl.h"

extern Tokenizer t;

void Decl::parseDecl()
{
  curToken=t.getToken();
  if(curToken == 4){
    t.skipToken();
    idl.parseIDListForDS();
  }
  else 
  {
    cout<<"Error - expecting int"<<endl; 
    exit(1);
  }

  curToken=t.getToken();
  if(curToken == 12) {
    curToken=t.getToken();
  }
  else
  {
    cout<<"Error - expecting ;"<<endl; 
    exit(1);
  }
}

void Decl::printDecl()
{
  curToken=t.getToken();
  while(curToken != 12)
  {
    if(curToken==4) { 
      cout<<"   int "; 
      t.skipToken(); 
      curToken=t.getToken(); 
    }
    else if(curToken==13) { 
      cout<<", "; 
      t.skipToken(); 
      curToken=t.getToken(); 
    }
    idl.printIDList();
    t.skipToken();
    curToken=t.getToken();
  }
  cout<<" ;";
}

void Decl::execDecl()
{
}
