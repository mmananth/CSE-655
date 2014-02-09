#ifndef _IDLIST_H_
#define _IDLIST_H_
#include "ID.h"

class idList:public Tokenizer
{
public:
  idList(){};
  ID id;
  int curToken;
  int idValue,gnext;
  string strID;
  //ID(string) id;
  void parseIDListForDS();
  void parseIDListForSS();
  void printIDList();
  void readInput();
  void writeOutput();
};

#endif 
