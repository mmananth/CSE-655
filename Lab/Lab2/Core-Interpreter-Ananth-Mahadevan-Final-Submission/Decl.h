#ifndef _DECLARATION_H_
#define _DECLARATION_H_
#include "idList.h"

class Decl:public Tokenizer
{
private:
  int curToken;
public:
  Decl(){};
  idList idl; 
  void parseDecl();
  void printDecl();
  void execDecl();
};

#endif 
