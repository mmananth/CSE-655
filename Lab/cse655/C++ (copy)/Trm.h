#ifndef _TRM_H_
#define _TRM_H_

class Trm:public Tokenizer
{
public:
  Trm(){};
  Operator oper;
  int curToken, resultTrm;
  void parseTrm();
  void printTrm();
  int execTrm();
};

#endif 
