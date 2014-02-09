#ifndef _DIGIT_H_
#define _DIGIT_H_

class Digit:public Tokenizer
{
public:
  Digit(){};
  int curToken;
  void parseDigit();
  void printDigit();
  void execDigit();
};

#endif 
