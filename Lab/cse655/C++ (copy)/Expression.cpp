#include "Expression.h"

extern Tokenizer t;

void Expression::parseExpression()
{
  curToken=t.getToken();
  trm.parseTrm();

  if(curToken == 22) {
    altNum=2;
    t.skipToken();
    parseExpression();
  }
  else if(curToken == 23) {
    altNum=3;
    t.skipToken();
    parseExpression();
  }
}

void Expression::printExpression()
{
  if(altNum == 1) {
    trm.printTrm();
  } else if(altNum == 2){
      trm.printTrm();
      cout<<"+";
      printExpression();
  } else if(altNum ==3) {
      trm.printTrm();
      cout<<"-";
      printExpression();
  }
}

int Expression::execExpression()
{
  if(altNum==1) {
    return trm.execTrm();
  } else if (altNum==2) {
    return (trm.execTrm() + execExpression());
  } else {
      return (trm.execTrm() - execExpression());
  }
}
