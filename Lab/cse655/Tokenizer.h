#ifndef _TOKENIZER_H
#define _TOKENIZER_H
#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<locale>

using namespace std;

class Tokenizer
{
private:
  locale loc;
  string lines[1000],line,lines1[1000],line1,lineCnt,substring1;
  char *ch, *chra, *cha, *cstr, *cstra, *pt, *pt1, *pta, c, *cstr1;

  size_t found;
  int k,n,m,count;
  //static int count;
  int flag_Plus, flag_Equal, flag_LeftParentheses, flag_Semicolon, flag_Num, flag_Upper, flag_Alnum, flag_RightParentheses, flag_Comma, flag_Variable, flag_LeftSquare, flag_RightSquare, good, index;
  //int tokenDone;
  //static int tokenDone;

  ifstream istr, istr2, istr3;
  ofstream ostr, ostr2;

public:
  /*void intVal();
  void idName();
  void processFile();*/
  //static int tokenDone;
  Tokenizer();
  void getInput(char* arg);
  int getToken();
  void parseToken();
  void skipToken();
  void setIndex(int);
  void printLines();
  string getIdName();
};
#endif
