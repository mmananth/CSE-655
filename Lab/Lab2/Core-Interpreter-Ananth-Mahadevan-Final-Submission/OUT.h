#ifndef _OUT_H_
#define _OUT_H_
#include "Tokenizer.h"
#include "idList.h"

class idList;
class OUT:public Tokenizer
{
private:
  int curToken;
public:
  idList *idl;
  OUT(){ idl=NULL; };
  ~OUT();
  void parseOUT();
  void printOUT();
  void execOUT();
  idList* getidListInstance();
};

#endif 
