#ifndef _COREHEADER_H_
#define _COREHEADER_H_
#include <iostream>
#include <fstream>
#include <string>
#include "DeclSeq.h"
#include "StmtSeq.h"
#include "ID.h"

class Program:public Tokenizer
{
//private:
  //DeclSeq ds;
  //StmtSeq ss;
public:
  ifstream ifstr;
  string linesFile2[100],lineFile2;
  char* cstr2, *pt2;
  Program(){};
  int curToken,countFile2;
  DeclSeq ds;
  StmtSeq ss;
  ID id;
  void parseInputFile2(char* arg);
  void parseProgram();
  void printProgram();
  void execProgram();
};

#endif 
