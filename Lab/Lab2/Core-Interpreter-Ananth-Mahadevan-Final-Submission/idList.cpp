/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for processing the individual variables	*/
/****************************************************************/
#include "idList.h"

extern Tokenizer t;

void idList::parseIDListForDS()
{
  curToken=t.getToken();
  while(curToken != 12){
  if(curToken == 32) {
    id.parseIDForDS();
    t.skipToken();
    curToken=t.getToken();
  }
  else if(curToken == 13){
    t.skipToken();
    curToken=t.getToken();
  }
 }
}

void idList::parseIDListForSS()
{
  curToken=t.getToken();
  if(curToken == 32) {
    id.parseIDForSS();
  }
  if(curToken == 13){
    t.skipToken();
    curToken=t.getToken();
    if(curToken == 32){
      id.parseIDForSS();
    } 
    else {
      cout<<"Error-Expecting an integer value. Exiting"<<endl;
      exit(0);
    }
  }
}

void idList::printIDList()
{
  strID=t.getIdName();
  cout<<strID;
}

/*To get the values from the InputFile*/
void idList::readInput()
{
  //p=new Program();
  //gnext=p.getNextInputVal();
  //id.setIDValString(gnext);
  //delete p;
  //gnext=t.intVal();
  //id.setIDValString(gnext);
  //readInput();
}

void idList::writeOutput()
{
  idValue=id.getIDValString();
  cout<<idValue;
}
