#include<fstream>
#include<iostream>
#include<string>
#include<map>

using namespace std;

class tokenizer1
{
public:
  char readRec();
private:
  void getToken();
  void skipToken();
  void intVal();
  void idName();
};

int main(int argc, char* argv[])
{
/***********************************************************
*Variable declaration
***********************************************************/
  string rw[11]={"program","begin","end","int","if","then","else","while","loop","read","write"};
  string spe_sym[19]={";",",","=","!","[","]","&&","||","(",")","+","-","*","!=","==","<",">","<=",">="};
  string num[10]={"0","1","2","3","4","5","6","7","8","9"};
  string chr[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  int k=0,n=0,count=0,p=12,c=1;
  tokenizer1 t;
  string lines[100],line,lineCnt;
  char * ch;
  ifstream inFile1(argv[1]);
  ifstream inFile(argv[1]);
  vector<string> lineCount;
  multimap<string,int> T;
  pair<multimap<string,int>::iterator, multimap<string,int>::iterator> mp;

/***********************************************************
*Get the count of the lines in the input file
***********************************************************/
  while(getline(inFile1,lineCnt)) lineCount.push_back(lineCnt);
  {
  	n=lineCount.size();
  }


/******************************************************************
*Build a map with the tokens and their corresponding integer values
******************************************************************/
  for(int e=0;e<11;e++)
  {
    T.insert(pair<string,int>(rw[e],c));
    c++;
  }
  for(int e=0;e<19;e++)
  {
    T.insert(pair<string,int>(spe_sym[e],p));
    p++;
  }
  for(int e=0;e<10;e++)
  {
    T.insert(pair<string,int>(num[e],31));
  }
  for(int e=0;e<26;e++)
  {
    T.insert(pair<string,int>(chr[e],32));
  }

/******************************************************************
*Go through the file and get the individual tokens.
*Look up their corresponding integer values from the map
******************************************************************/
  while(getline(inFile,line))
    {
      lines[count++]=line;
    }

  for(k=0;k<n;k++)
    {
      char *a=(char*)lines[k].c_str();
      ch=strtok(a," \r\t");
      mp = T.equal_range(ch);
  
      while(ch != NULL)
	{
          mp = T.equal_range(ch);
          for(multimap<string,int>::iterator it = mp.first; it != mp.second; ++it)
	  {
	    cout<<(*it).second << endl;
	  }
	  ch=strtok(NULL," \n\r\t");
	}
    }
}

/*
char tokenizer::readRec()
{
}

void tokenizer::getToken()
{
}

void tokenizer::skipToken()
{
}

void tokenizer::intVal()
{
}

void tokenizer::idName()
{
}
*/
