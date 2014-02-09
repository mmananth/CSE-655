#ifndef _NUMBER_H_
#define _NUMBER_H_
#include "Digit.h"

class Number:public Tokenizer
{
public:
  Number() {};
  int curToken;
  Digit digit;
  void parseNumber();
  void printNumber();
  void execNumber();
};

#endif 
