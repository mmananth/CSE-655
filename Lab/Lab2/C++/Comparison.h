#ifndef _COMPARISON_H_
#define _COMPARISON_H_

class Comparison:public Tokenizer
{
public:
  Comparison() {};
  Tokenizer t;
  void parseComparison();
};

#endif 
