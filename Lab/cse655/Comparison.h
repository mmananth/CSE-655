#ifndef _COMPARISON_H_
#define _COMPARISON_H_
#include "Tokenizer.h"

class Comparison:public Tokenizer
{
public:
  Comparison() {};
  Tokenizer t;
  void parseComparison();
};

#endif 
