#include "Expression.h"

extern Tokenizer t;

void Expression::parseExpression()
{
  curToken=t.getToken();
  trm.parseTrm();
  //if( (curToken == 22) && (curToken == 23) )
    
}

void Expression::printExpression()
{
}

void Expression::execExpression()
{
}
