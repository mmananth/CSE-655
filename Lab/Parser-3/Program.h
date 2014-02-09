#ifndef _COREHEADER_H_
#define _COREHEADER_H_
#include "DeclSeq.h"
#include "StmtSeq.h"
#include "ID.h"

class Program:public Tokenizer
{
//private:
  //DeclSeq ds;
  //StmtSeq ss;
public:
  DeclSeq ds;
  StmtSeq ss;
  ID id;
  ifstream ifstr;
  string linesFile2[100],lineFile2;
  char* cstr2, *pt2;
  int curToken,countFile2,index2;
  Program(){ index2=0; } ;
  void parseInputFile2(char* arg);
  int getNextInputVal();
  void parseProgram();
  void printProgram();
  void execProgram();
};

#endif 
