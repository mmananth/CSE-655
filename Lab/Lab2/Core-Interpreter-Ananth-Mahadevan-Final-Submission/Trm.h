#ifndef _TRM_H_
#define _TRM_H_
#include "ConflictRes.h"

class Operator;
class Trm:public Tokenizer
{
private:
  int curToken, resultTrm;
public:
  Operator *oper;
  Trm(){ oper=NULL; };
  ~Trm();
  void parseTrm();
  void printTrm();
  int execTrm();
  Operator* getOperInstanceTrm();
};

#endif 
