#ifndef _OUT_H_
#define _OUT_H_
#include "idList.h"

class OUT:public Tokenizer
{
public:
  OUT(){};
  idList idl;
  int curToken;
  void parseOUT();
  void printOUT();
  void execOUT();
};

#endif 
