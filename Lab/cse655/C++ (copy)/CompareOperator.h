#ifndef _COMPAREOPERATOR_H_
#define _COMPAREOPERATOR_H_

class CompareOperator:public Tokenizer
{
public:
  CompareOperator(){};
  int curToken;
  int altNum;
  void parseCompareOperator();
  void printCompareOperator();
  void execCompareOperator();
};

#endif 
