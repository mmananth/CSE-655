/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for getting the values present in the second*/
/* command line file						*/
/****************************************************************/
#include "IN.h"

extern Tokenizer t;

IN::~IN()
{
  delete idl;
}

void IN::parseIN()
{
  curToken=t.getToken();
  if(curToken == 10){
    t.skipToken();
    this->getidListInstanceIN()->parseIDListForSS();
    t.skipToken();
    curToken=t.getToken();
  }
  else {
    cout<<"Error-expecting read"<<endl;
    exit(0);
  }
  if(curToken == 12) {
    t.skipToken();
  }
  else{
    cout<<"IN Error-expecting ;"<<endl;
    exit(0);
  }
}

void IN::printIN()
{
  this->getidListInstanceIN()->printIDList();
}

void IN::execIN()
{
  this->getidListInstanceIN()->readInput();
}

idList* IN::getidListInstanceIN()
{
  if(idl==NULL)
    return new idList();
  else
    return idl;
}

