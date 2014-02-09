#include "Operator.h"

extern Tokenizer t;

void Operator::parseOperator()
{
  curToken=t.getToken();
  numb.parseNumber();
  id.parseIDForSS();
}

void Operator::printOperator()
{
}

void Operator::execOperator()
{
}
