/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Used for parsing the values present in the second*/
/* file; for calling the parse, print and execute functions of  */
/* the Core program interpreter					*/
/****************************************************************/
#include "Program.h"

extern Tokenizer t;

void Program::parseInputFile2(char* arg2) {
  countFile2=0;
  ifstr.open(arg2,ifstream::in);
  if(!ifstr.is_open())
  {
    cout<<"Unable to open file "<<endl;
    exit(1);
  }

  while(getline(ifstr,lineFile2)) {
    linesFile2[countFile2++]=lineFile2;
  }
  ifstr.close();

  int u=0;
  cstr2=new char[100];
  for(int i=0;i<countFile2;i++)
  {
    strcpy(cstr2,linesFile2[i].c_str());
    pt2=strtok(cstr2," \t");
    while(pt2!=NULL)
    {
      linesFile2[u++]=pt2;
      pt2=strtok(NULL," \t");
    }
  }
}

/*******************************************************************/

string Program::getNextInputVal()
{
  return linesFile2[indexFor2];
  indexFor2++;
}

/*******************************************************************/

void Program::parseProgram() {
    t.setIndex(-1);
    t.skipToken();
    curToken=t.getToken();
    //----------------------------------------------------------------//
    if(curToken == 1) {
      t.skipToken();
      curToken=t.getToken();
      while(curToken != 2) {
        ds.parseDS(); 
        t.skipToken();
        curToken=t.getToken();
      }
    }
    else {
      cout<<"error 1"<<endl;
      exit(1);
    }
    cout<<endl;
    //----------------------------------------------------------------
    if(curToken == 2) {
      t.skipToken();
      curToken=t.getToken();
      while(curToken != 3) {
        ss.parseSS(); 
        t.skipToken();
        curToken=t.getToken();
      }
    }
    else {
      cout<<"error 2"<<endl;
      exit(1);
    }
    cout<<endl;
    //----------------------------------------------------------------//
    if(curToken == 3) {
      t.skipToken();
      curToken=t.getToken();
      cout<<"End of Parsing. No errors found"<<endl;
    }
    else {
      cout<<"error 3"<<endl;
      exit(1);
    }
}

/*******************************************************************/

void Program::printProgram() {
    t.setIndex(-1);
    t.skipToken();
    curToken=t.getToken();
    //----------------------------------------------------------------//
    if(curToken == 1) {
      cout<<"program"<<endl;
      t.skipToken();
      curToken=t.getToken();
      while(curToken != 2) {
        ds.printDS();
	t.skipToken();
	curToken=t.getToken();
      }
    }
    else {
      cout<<"error 1"<<endl;
      exit(1);
    }
    cout<<endl;
    //----------------------------------------------------------------//
    if(curToken == 2) {
      cout<<endl<<"begin"<<endl;
      id.insertSpace();
      id.insertSpace();
      t.skipToken();
      curToken=t.getToken();
      while(curToken != 3) {
        ss.printSS();
        if(curToken==12) { cout<<" ;"; }
 	t.skipToken();
	curToken=t.getToken();
      }
    }
    else {
      cout<<"error 2"<<endl;
      exit(1);
    }
    cout<<endl;
    //----------------------------------------------------------------//
    curToken=t.getToken();
    if(curToken == 3) {
      cout<<endl<<"end"<<endl;
    }
    else {
      cout<<"error 3"<<endl;
    }
}

/*******************************************************************/

void Program::execProgram() {
    ss.execSS();
}
