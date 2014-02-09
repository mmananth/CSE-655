#ifndef _LETTER_H_
#define _LETTER_H_

class Letter:public Tokenizer
{
public:
  Letter() {};
  int curToken;
  void parseLetter();
  void printLetter();
  void execLetter();
};

#endif 
