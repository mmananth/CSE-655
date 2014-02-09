#include "Number.h"

extern Tokenizer t;

void Number::parseNumber()
{
  curToken=t.getToken();
  digit.parseDigit();
}

void Number::printNumber()
{
}

void Number::execNumber()
{
}
