#ifndef _IF_H_
#define _IF_H_

class IF:public Tokenizer
{
public:
  IF(){};
  Condition cond;
  StmtSeq ss;
  int curToken;
  bool valueIfBool;
  void parseIF();
  void printIF();
  void execIF();
};

#endif 
