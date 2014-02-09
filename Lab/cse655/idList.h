#ifndef _IDLIST_H_
#define _IDLIST_H_
#include "Tokenizer.h"
#include "ID.h"

class idList:public Tokenizer
{
public:
  idList(){};
  ID id;
  int curToken;
  //ID(string) id;
  void parseIdListForDS();
  void parseIdListForSS();
  void printIdList();
  void execIdList();
};

#endif 
