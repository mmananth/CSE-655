#include "OUT.h"

extern Tokenizer t;

void OUT::parseOUT()
{
  curToken=t.getToken();
  while(curToken != 12){
    idl.parseIdListForSS();
    curToken=t.getToken();
    t.skipToken();
  }
}

void OUT::printOUT()
{
}

void OUT::execOUT()
{
  curToken=t.getToken();
  while(curToken != 12){
    idl.parseIdListForSS();
    curToken=t.getToken();
    t.skipToken();
  }
}
