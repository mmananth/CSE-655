#include "DeclSeq.h"

extern Tokenizer t;

void DeclSeq::parseDS()
{
  curToken=t.getToken();
  decl.parseDecl();
  if (curToken == 4)
  {
    parseDS();
  }
}

void DeclSeq::printDS()
{
  decl.printDecl();
}

void DeclSeq::execDS()
{
}
