/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Calls the Operator functions for processing the input*/
/****************************************************************/
#include "Operator.h"

extern Tokenizer t;

Trm::~Trm()
{
  delete oper;
}

void Trm::parseTrm()
{
  curToken=t.getToken();
#ifdef ENABLE_DEBUG_PARSE
  cout<<"curToken in parseTrm "<<curToken<<endl;
#endif
  this->getOperInstanceTrm()->parseOperator();
  if(curToken == 24)
  {
    t.skipToken();
    parseTrm();
  }
}

void Trm::printTrm()
{
  this->getOperInstanceTrm()->printOperator();
}

int Trm::execTrm()
{
  resultTrm=(this->getOperInstanceTrm()->execOperator() * execTrm());
  return resultTrm;
}

Operator* Trm::getOperInstanceTrm()
{
  if(oper==NULL)
    return new Operator();
  else
    return oper;
}
