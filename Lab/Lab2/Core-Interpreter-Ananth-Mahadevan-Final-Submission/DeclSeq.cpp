/************************************************************************/
/*CSE655-Core-Interpreter				     		*/
/*Author: Ananth Mahadevan				     		*/
/*Description: Calls the Decl.cpp functions				*/ 
/************************************************************************/
#include "DeclSeq.h"

extern Tokenizer t;

void DeclSeq::parseDS()
{
  curToken=t.getToken();
  decl.parseDecl();
}

void DeclSeq::printDS()
{
  decl.printDecl();
}

void DeclSeq::execDS()
{
}
