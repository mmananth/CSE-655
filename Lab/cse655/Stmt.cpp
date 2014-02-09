#include "Stmt.h"

extern Tokenizer t;

void Stmt::parseStmt()
{
  curToken=t.getToken();     
 
/*  if(curToken == 32)
  {
    altNum=1;
    assign.parseAssign();
  }

  else if(curToken == 5)
  {
    altNum=2;
    pif.parseIF();
    if(pif.checkIf == pif.checkIfEnd) { cout<<"If and End match "<<endl; }
    else { cout<<"No matching end for If. Exiting... "<<endl; }
  }

  else if(curToken == 8)
  {
    altNum=3;
    loop.parseLoop();
    if(loop.checkWhile == loop.checkWhileEnd) { cout<<"While and End match "<<endl; }
    else { cout<<"No matching end for While. Exiting... "<<endl; }
  }

  else if(curToken == 10)
  {
    altNum=4;
    in.parseIN();
  }

  else if(curToken == 11)
  {
    altNum=5;
    out1.parseOUT();
  }
  else 
    cout<<"Error in Stmt.cpp. Exiting..."<<endl;*/
}

void Stmt::printStmt()
{
/*  if(altNum==1) {
    assign.printAssign();
  }
  if(altNum==2) {
    pif.printIF();
  }
  if(altNum==3) {
    loop.printLoop();
  }
  if(altNum==4) {
    in.printIN();
  }
  if(altNum==5) {
    out.printOUT();
  }*/
}

void Stmt::execStmt()
{
  /*if(altNum==1) {
    assign.execAssign();
  }
  if(altNum==2) {
    pif.execIF();
  }
  if(altNum==3) {
    loop.execLoop();
  }
  if(altNum==4) {
    in.execIN();
  }
  if(altNum==5) {
    out.execOUT();
  }*/
}
