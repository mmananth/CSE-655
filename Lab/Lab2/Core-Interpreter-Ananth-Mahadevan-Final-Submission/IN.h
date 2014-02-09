#ifndef _IN_H_
#define _IN_H_
#include "Tokenizer.h"
#include "idList.h"

class idList;
class IN:public Tokenizer
{
private:
  int curToken;
public:
  idList *idl;
  IN(){ idl=NULL; };
  ~IN();
  void parseIN();
  void printIN();
  void execIN();
  idList* getidListInstanceIN();
};

#endif 
