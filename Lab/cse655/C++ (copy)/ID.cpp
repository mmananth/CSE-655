#include "ID.h"

extern Tokenizer t;

//static int idCount=0;
static ID* eIDs[20];
static int idCount = 0;

ID* ID::parseIDForDS()
{
    string idName=t.getIdName();
    for(int k=0; k<idCount; k++)
    {
      if(idName==eIDs[k]->name) {
	cout<<"Error - variable has already been declared"<<endl;
	exit(0);
      }
        ID *nID = new ID(idName);
        eIDs[idCount++]=nID;
        return nID;
    }
}

ID* ID::parseIDForSS()
{
    string idName=t.getIdName();
    for(int k=0; k<idCount; k++)
    {
      if(idName==eIDs[k]->name) {
        t.skipToken();
        return eIDs[k];
      }
        //ID nID(idName);
        //eIDs[idCount++]=nID;
        //return nID;
    }
    cout<<"Error - variable has already been declared"<<endl;
    exit(0);
}

/*void ID::printID()
{
  curToken=t.getToken();
  if(curToken == 4) {
    insertSpace();
    insertSpace();
  }
  else if(curToken == 5) {
    cout<<endl;
    insertSpace();
    insertSpace();
  }
  else if(curToken == 6) {
    insertSpace();
    insertSpace();
  }
  else if(curToken == 8) {
    cout<<endl;
    insertSpace();
    insertSpace();
  }
  else if(curToken == 9) {
    insertSpace();
    insertSpace();
  }
  else if(curToken == 10) {
    insertSpace();
    insertSpace();
  }
  else if(curToken == 11) {
    insertSpace();
    insertSpace();
  }
  else if( (curToken != 12) && (curToken != 13) && (curToken != 15) && (curToken != 16) && (curToken != 17) && (curToken !=20) && (curToken != 21) && (curToken != 27) && (curToken != 28) )
  {
    insertSpace();
  }
    t.printLines();
}*/

void ID::insertSpace()
{
  cout<<" ";
}

string ID::getIDName()
{
}

void ID::setIDVal(int)
{
}

int ID::getIDVal()
{
}
