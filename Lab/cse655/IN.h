#ifndef _IN_H_
#define _IN_H_
#include "Tokenizer.h"
#include "idList.h"

class IN:public Tokenizer
{
public:
  IN(){};
  int curToken;
  idList idl;
  void parseIN();
  void printIN();
  void execIN();
};

#endif 
