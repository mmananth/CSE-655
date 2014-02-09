#include "idList.h"

extern Tokenizer t;

void idList::parseIdListForDS()
{
  curToken=t.getToken();
  if(curToken == 13){
    t.skipToken();
    curToken=t.getToken();
    if(curToken == 32){
      id.parseIDForDS();
    } 
    else {
      cout<<"Error-Expecting an integer value. Exiting"<<endl;
      exit(0);
    }
  }
}

void idList::parseIdListForSS()
{
  curToken=t.getToken();
  if(curToken == 13){
    t.skipToken();
    curToken=t.getToken();
    if(curToken == 32){
      id.parseIDForDS();
    } 
    else {
      cout<<"Error-Expecting an integer value. Exiting"<<endl;
      exit(0);
    }
  }
}

void idList::printIdList()
{
  id.printID();
}

void idList::execIdList()
{
}
