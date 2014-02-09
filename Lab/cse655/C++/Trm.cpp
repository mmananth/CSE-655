#include "Trm.h"

extern Tokenizer t;

void Trm::parseTrm()
{
  curToken=t.getToken();
  oper->parseOperator();
  if(curToken == 24)
  {
    t.skipToken();
    parseTrm();
  }
}

void Trm::printTrm()
{
  oper->printOperator();
  cout<<"*";
  printTrm();
}

int Trm::execTrm()
{
  resultTrm=(oper->execOperator() * execTrm());
  return resultTrm;
}
