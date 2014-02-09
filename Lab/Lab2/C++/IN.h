#ifndef _IN_H_
#define _IN_H_
#include "Tokenizer.h"
#include "idList.h"

class idList;
class IN:public Tokenizer
{
public:
  idList *idl;
  IN(){ idl=NULL; };
  ~IN();
  int curToken;
  void parseIN();
  void printIN();
  void execIN();
  idList* getidListInstanceIN();
};

#endif 
