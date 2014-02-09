/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for writing values read from the input file */
/* to the standard screen					*/
/****************************************************************/
#include "OUT.h"

extern Tokenizer t;

OUT::~OUT()
{
  delete idl;
}

void OUT::parseOUT()
{
  curToken=t.getToken();
  if(curToken == 11){
    t.skipToken();
    this->getidListInstance()->parseIDListForSS();
  }
  else {
    cout<<"Error-expecting write"<<endl;
    exit(0);
  }
  t.skipToken();
  curToken=t.getToken();
  if(curToken == 12) {
    cout<<"";
  }
  else {
    cout<<"Error-expecting ;"<<endl;
    exit(0);
  }
}

void OUT::printOUT()
{
  this->getidListInstance()->printIDList();
}

void OUT::execOUT()
{
  this->getidListInstance()->writeOutput();
}

idList* OUT::getidListInstance()
{
  if(idl==NULL)
    return new idList();
  else 
    return idl;
}
