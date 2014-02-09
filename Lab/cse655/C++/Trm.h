#ifndef _TRM_H_
#define _TRM_H_
#include "ConflictRes.h"

class Operator1;
class Trm:public Tokenizer
{
public:
  Trm(){};
  Operator1 *oper;
  int curToken, resultTrm;
  void parseTrm();
  void printTrm();
  int execTrm();
};

#endif 
