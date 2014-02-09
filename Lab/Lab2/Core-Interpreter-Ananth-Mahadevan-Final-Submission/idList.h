#ifndef _IDLIST_H_
#define _IDLIST_H_
#include "ID.h"

class idList:public Tokenizer
{
private:
  int curToken;
  string idValue;
public:
  string strID,gnext;
  idList(){ gnext=""; };
  ID id;
  void parseIDListForDS();
  void parseIDListForSS();
  void printIDList();
  void readInput();
  void writeOutput();
};

#endif 
