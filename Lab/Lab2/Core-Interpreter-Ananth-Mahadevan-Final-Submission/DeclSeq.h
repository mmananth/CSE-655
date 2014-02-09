#ifndef _DECLARATIONSEQUENCE_H
#define _DECLARATIONSEQUENCE_H
#include "Decl.h"
#include "idList.h"

class DeclSeq:public Tokenizer
{
private:
  int curToken;
public:
  DeclSeq(){};
  Decl decl;
  idList idl;
  void parseDS();
  void printDS();
  void execDS();
};

#endif 
