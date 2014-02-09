#ifndef _ID_H_
#define _ID_H_
#include "Tokenizer.h"
#include "Letter.h"
#include "Number.h"

class ID:public Tokenizer
{
  string name;
  int val;
  bool declared;
  bool initialized;
  //static ID* eIDs[20];
  //static int idCount;
  ID(string n) {
    name=n;
    declared=false;
    initialized=false;
  }
public:
  ID(){};
  int curToken;
  Letter let;
  Number numb;
  //int getIDCal() { return val;}
  void setIDVal();
  void getIDName();
  static ID* parseIDForDS();
  static ID* parseIDForSS();
  void printID();
  void execID();
  void insertSpace();
};

#endif 
