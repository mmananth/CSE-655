#ifndef _IDLIST_H_
#define _IDLIST_H_
#include "ID.h"

class idList:public Tokenizer
{
public:
  string strID,gnext;
  idList(){ gnext=""; };
  ID id;
  int curToken;
  string idValue;
  void parseIDListForDS();
  void parseIDListForSS();
  void printIDList();
  void readInput();
  void writeOutput();
};

#endif 
