#ifndef _DECLARATIONSEQUENCE_H
#define _DECLARATIONSEQUENCE_H
#include "Tokenizer.h"
#include "Decl.h"
#include "idList.h"

class DeclSeq:public Tokenizer
{
public:
  DeclSeq(){};
  int curToken;
  Decl decl;
  idList idl;
  void parseDS();
  void printDS();
  void execDS();
};

#endif 
