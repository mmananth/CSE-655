#ifndef _DECLARATION_H_
#define _DECLARATION_H_
#include "Tokenizer.h"
#include "idList.h"

class Decl:public Tokenizer
{
public:
  Decl(){};
  idList idl; 
  int curToken;
  //IdList idlist;
  void parseDecl();
  void printDecl();
  void execDecl();
};

#endif 
