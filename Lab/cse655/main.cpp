#include "Tokenizer.h"
#include "Program.h"

Tokenizer t;
int main(int argc, char* argv[])
{
    Program p;
    t.setIndex(-1);
    t.getInput(argv[1]);
    t.skipToken();
    int tok=t.getToken();
    cout<<"------------------------------------------------"<<endl;
    cout<<"The tokens for the given input "<<argv[1]<<" are:"<<endl;
    cout<<"------------------------------------------------"<<endl;
    while(tok != 33)
    {
        tok=t.getToken();
        t.skipToken();
        if(tok == -1)
            cout<<"error in input"<<endl;
        else if(tok == -2)
        {
            cout<<"error at the end of the inputfile"<<endl;
            cout<<33<<endl;
            break;
        }
        else{ 
            cout<<tok<<endl;
        }
    }
    //string name=t.idName(1);
    //cout<<"name is"<<name<<endl;
    cout<<"------------------------------------------------"<<endl;
    p.parseProgram();
    
    /*cout<<"------------------------------------------------"<<endl;
     cout<<"The pretty print version of the input file is:"<<endl;
     cout<<"------------------------------------------------"<<endl;
     p.printProgram();
     
     cout<<"------------------------------------------------"<<endl;
     cout<<"Beginning execution..."<<endl;
     p.parseInputFile2(argv[2]);
     p.execProgram();*/
}
