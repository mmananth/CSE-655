#include "idList.h"

extern Tokenizer t;

void idList::parseIDListForDS()
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

void idList::parseIDListForSS()
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

void idList::printIDList()
{
  strID=id.getIDName();
  cout<<strID<<endl;
  cout<<", ";
  printIDList();
}

void idList::readInput()
{
  //gnext=t.getNext();
  //id.setIDVal(gnext);
  readInput();
}

void idList::writeOutput()
{
  cout<<" = ";
  idValue=id.getIDVal();
  cout<<idValue;
  writeOutput();
}
