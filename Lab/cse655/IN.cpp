#include "IN.h"

extern Tokenizer t;

void IN::parseIN()
{
  curToken=t.getToken();
  while(curToken != 12){
    idl.parseIdListForSS();
    curToken=t.getToken();
    t.skipToken();
  }
}

void IN::printIN()
{
}

void IN::execIN()
{
}
