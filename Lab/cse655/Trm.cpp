#include "Trm.h"

extern Tokenizer t;

void Trm::parseTrm()
{
  curToken=t.getToken();
  op.parseOperator();
}

void Trm::printTrm()
{
}

void Trm::execTrm()
{
}
