#ifndef _TRM_H_
#define _TRM_H_
#include "Tokenizer.h"
#include "Operator.h"

class Trm:public Tokenizer
{
public:
  Trm() {};
  int curToken;
  Operator op;
  void parseTrm();
  void printTrm();
  void execTrm();
};

#endif 
