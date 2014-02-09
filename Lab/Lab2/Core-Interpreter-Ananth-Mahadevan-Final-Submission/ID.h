#ifndef _ID_H_
#define _ID_H_
#include "Tokenizer.h"
#include "ID.h"
#include <string>

class ID:public Tokenizer
{
private:
  string name,strVal;
  int val, curToken;
  bool declared;
  bool initialized;
  ID(string n) {
    name=n;
    declared=false;
    initialized=false;
  };
public:
  ID(){};
  void setIDVal(int);
  void setIDValString(string);
  int getIDVal();
  string getIDValString();
  string getIDName();
  static ID* parseIDForDS();
  static ID* parseIDForSS();
  void insertSpace();
  void getInitialized();
  void printID();
};

#endif 
