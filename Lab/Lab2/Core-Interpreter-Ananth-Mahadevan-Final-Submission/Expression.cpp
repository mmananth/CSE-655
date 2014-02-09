/********************************************************/
/*CSE655-Core-Interpreter				*/
/*Author: Ananth Mahadevan				*/
/*Description: Used for processing Addition, Subtraction*/
/*operations						*/
/********************************************************/
#include "Expression.h"

extern Tokenizer t;

Expression::~Expression()
{
  delete trm;
}

void Expression::parseExpression()
{
  curToken=t.getToken();
#ifdef ENABLE_DEBUG_PARSE
  cout<<"curToken in parseExpression "<<curToken<<endl;
#endif
  altNum=1;
  this->getTrmInstance()->parseTrm();

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
    this->getTrmInstance()->printTrm();
    curToken=t.getToken();
    if(curToken == 22){
      cout<<" + ";
      this->getTrmInstance()->printTrm();
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printExpression- + "<<curToken<<endl;
#endif
    } 
    else if(curToken == 23) {
      cout<<" - ";
      this->getTrmInstance()->printTrm();
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printExpression- -- "<<curToken<<endl;
#endif
    }
    else if(curToken == 14) {
      cout<<" = ";
      this->getTrmInstance()->printTrm();
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printExpression- = "<<curToken<<endl;
#endif
    }
    else if(curToken==12) {
      cout<<" ; ";
      curToken=t.getToken();
#ifdef ENABLE_DEBUG_PRINT
      cout<<" curToken-printExpression- ; "<<curToken<<endl;
#endif
      if(curToken==7) { cout<<endl<<" else "<<endl; }
    }
}

int Expression::execExpression()
{
  if(altNum==1) {
    return this->getTrmInstance()->execTrm();
  } else if (altNum==2) {
    return (this->getTrmInstance()->execTrm() + execExpression());
  } else {
      return (this->getTrmInstance()->execTrm() - execExpression());
  }
}

Trm* Expression::getTrmInstance()
{
  if(trm==NULL)
    return new Trm();
  else
    return trm; 
}
