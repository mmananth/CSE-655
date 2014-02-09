#ifndef _LOOP_H_
#define _LOOP_H_
#include "Tokenizer.h"

class Loop:public Tokenizer
{
public:
  Loop() {};
  int checkWhile, checkWhileEnd;
  int curToken;
  void parseLoop();
  void printLoop();
  void execLoop();
};

#endif 
