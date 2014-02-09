#ifndef _IN_H_
#define _IN_H_
#include "Tokenizer.h"
#include "idList.h"

class idList;
class IN:public Tokenizer
{
public:
  IN(){};
  idList* idl;
  int curToken;
  void parseIN();
  void printIN();
  void execIN();
};

#endif 
