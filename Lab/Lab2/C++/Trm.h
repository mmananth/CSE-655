#ifndef _TRM_H_
#define _TRM_H_
#include "ConflictRes.h"

class Operator;
class Trm:public Tokenizer
{
public:
  Operator *oper;
  Trm(){ oper=NULL; };
  ~Trm();
  int curToken, resultTrm;
  void parseTrm();
  void printTrm();
  int execTrm();
  Operator* getOperInstanceTrm();
};

#endif 
