/************************************************************************/
/*CSE655-Core-Interpreter				     		*/
/*Author: Ananth Mahadevan				     		*/
/*Description: Checks for negation(!=), AND (&&), OR (||) operators	*/ 
/*and calls the appropriate function      		     		*/
/************************************************************************/
#include "Condition.h"

extern Tokenizer t;

void Condition::parseCondition()
{
  curToken=t.getToken();
  //Check if token is ( and call Compare.cpp's parse operation
  if(curToken == 20) {
    altNum=1;
    comp.parseCompare();
  }
  else if(curToken == 15) {
    altNum=2;
    t.skipToken();
    parseCondition();
  }
  else if(curToken == 16) {
    t.skipToken();
    parseCondition();
    curToken=t.getToken();
    if(curToken == 18){
      altNum=3;
    }
    else if(curToken == 19){
      altNum=4;
    }
    else{
      cout<<"Error-expecting && or ||"<<endl;
      exit(0);
    }
    t.skipToken();
    parseCondition();
    curToken=t.getToken();
    if(curToken == 17) {
      t.skipToken();
    }
    else {
      cout<<"Error-expecting ]"<<endl;
      exit(0);
    }
  } 
  else {
    cout<<"Error. Exiting"<<endl;
    exit(0);
  }
}

void Condition::printCondition()
{
  comp.printCompare();
}

bool Condition::execCondition()
{
  comp.execCompare();
}
