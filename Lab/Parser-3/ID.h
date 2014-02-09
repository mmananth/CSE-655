#ifndef _ID_H_
#define _ID_H_
#include "Tokenizer.h"
#include "ID.h"
#include <string>

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
  };
public:
  ID(){};
  int curToken;
  //int getIDCal() { return val;}
  void setIDVal(int);
  int getIDVal();
  string getIDName();
  static ID* parseIDForDS();
  static ID* parseIDForSS();
  void insertSpace();
  void getInitialized();
};

#endif 
