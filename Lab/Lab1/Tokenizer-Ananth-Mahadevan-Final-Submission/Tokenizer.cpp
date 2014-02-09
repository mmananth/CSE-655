#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<locale>

using namespace std;

class tokenizer1
{
public:
  char readRec();
  void dispResWord(char *ab);
  void dispSpeSym(char *cd);
  void dispIntegers(char *ef);
  void dispIdentifiers(char *gh);
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

  string lines[1000],line,lineCnt,substring1;
  char *ch, *chra, *cha, *charac, *cstr, *cstra, *pt, *pta, c;

  size_t found;
  int k=0,n=0,count=0,p=12,q=1,m=0;
  int flag_ResWord=0, flag_Variable=0, flag_Number=0, flag_Punctuation=0, flag_Alphanumeric=0,flag_alphaFirstPass=0,flag_numberFirstPass=0, flag_alphaSmall=0, flag_Plus=0, flag_Equal=0, flag_Parentheses=0;

/***********************************************************
*Declare the file handler objects
***********************************************************/
  ifstream istr(argv[1]);
  if(!istr.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  ofstream ostr("output1.txt");
  if(!ostr.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  ifstream istr2("output1.txt");
  if(!istr2.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  ofstream ostr2("output2.txt");
  if(!ostr2.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  ifstream istr3("output2.txt");
  if(!istr3.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }

  multimap<string,int> T;
  pair<multimap<string,int>::iterator, multimap<string,int>::iterator> mp;

  tokenizer1 t;

/******************************************************************
*Build a multi-map with the tokens and their corresponding integer values
******************************************************************/
  for(int e=0;e<11;e++)
  {
    T.insert(pair<string,int>(rw[e],q));
    q++;
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
*Go through the file and get the values into an array.
******************************************************************/
  while(getline(istr,line))
    {
      lines[count++]=line;
    }

  //closing the object for the input file
  istr.close();

/************************************************************************************
*Use the string tokenizer function to get the tokens with space and tab as delimiters
************************************************************************************/
  cstr=new char[1000];
  for(int i=0;i<count;i++)
  {
    strcpy(cstr,lines[i].c_str());
    pt=strtok(cstr," \t");
    while(pt!=NULL)
    {
      ostr<<pt<<endl;
      pt=strtok(NULL," \t");
    }
  }

  count = 0;
  while(getline(istr2,line)) lines[count++]=line;

/************************************************************************************
*Manipulation of certain special symbols so that tokenizing becomes easier
************************************************************************************/
  for(int i=0;i<count;i++)
  {
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]=='+') 
	{
	  flag_Plus=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("+"), lines[i].length(), "@ ");
	}
      }

      if(flag_Plus==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), "+");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }

      for(int j=0;j<lines[i].size();j++)
      {
	if( ((lines[i][j]=='=') && (lines[i][j+1] == '=')) || ((lines[i][j] == '=') && (lines[i][j-1] == '=')) )
	{
	  cout<<endl;
	}
	else if(lines[i][j] =='=') 
	{
	  flag_Equal=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("="), lines[i].length(), "@ ");
	}
      }

      if(flag_Equal==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), "=");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }

      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]=='(') 
	{
	  flag_Parentheses=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("("), lines[i].length(), "@ ");
	}
      }

      if(flag_Parentheses==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), "(");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      flag_Plus=flag_Equal=flag_Parentheses=0;
  }

/************************************************************************************
*Further manipulation
************************************************************************************/
      cstra=new char[1000];
      for(int j=0;j<count;j++)
      {
 	strcpy(cstra,lines[j].c_str());
	pta=strtok(cstra," \t");
	while(pta!=NULL)
	{
	  ostr2<<pta<<endl;;
	  pta=strtok(NULL," \t");
	}
      }

  count = 0;
  while(getline(istr3,line)) lines[count++]=line;

/************************************************************************************
*This is the section that does the tokenizing of the values in the input file
************************************************************************************/
  for(int i=0;i<count;i++)
    {
      flag_ResWord=flag_Variable=flag_Alphanumeric=flag_Number=flag_Punctuation=flag_alphaFirstPass=flag_numberFirstPass=flag_alphaSmall=0;

      charac=(char*)lines[i].c_str();
      chra=strtok(charac," \n"); 
      for(int j=0;j<lines[i].size();j++)
      {
        c=lines[i][j];
	ch=&c;
        m=(int)c;

        if( ((m >= 65) && (m <= 90)) || ((m >= 97) && (m <= 122)) || ( flag_alphaFirstPass==1 && ((m >=48) && (m <= 57))) || ( flag_alphaFirstPass==1 &&  (((m >= 33) && (m <= 47)) || ((m >= 58) && (m <= 62))) ) )
        {
          flag_alphaFirstPass=1;
          if( (m >= 97) && (m <= 122) )
          {
	    flag_alphaSmall=1;
            for(int mm=0;mm<11;mm++)
	    {
	      found=lines[i].find(rw[mm]);
	      if(found!=string::npos)
	      {
	        cha=(char*)rw[mm].c_str();      
                flag_ResWord=1;
	      }
	    }//mm's for loop end here
          }//m's if loop ends here

          else if( ((m >=65) && (m <= 90)) && (lines[i][j+1]=='=') && (lines[i][j+2]=='=') )
          {
            cout<<32<<endl;
            flag_Variable=0;
          }

          else if( (m >= 65) && (m <= 90) )
          {
            flag_Variable=1;
          }

          else if( (flag_Variable==1) && (m >= 48) && (m <= 57) )
	  {
	    flag_Variable=1; 
   	  }

          else if( (flag_alphaSmall==1) && (m >= 48) && (m <= 57) )
          {
            flag_Alphanumeric=1;
            flag_ResWord=flag_Variable=flag_alphaFirstPass=0;
            cout<<"error"<<endl;
            break;
          }
        }//Alphabet's if loop ends here
/**************************************************************************/
        if( ((m >=48) && (m <= 57)) || ( flag_numberFirstPass==1 && (((m >= 65) && (m <= 90)) || ((m >= 97) && (m <= 122)))) )
        {
          flag_numberFirstPass=1;
          if( (flag_Variable==0) && (m >= 48) && (m <= 57) )
          {
            flag_Number=1;
          }
          else if( ((m >= 65) && (m <= 90)) || ((m >= 97) && (m <= 122)) )
          {
            flag_Alphanumeric=1;
            flag_ResWord=flag_Variable=flag_Number=flag_numberFirstPass=0;
            cout<<"error"<<endl;
            break;
          }
        }//Number's if loop ends here
/**************************************************************************/
        if( ((m >= 33) && (m <= 47)) || ((m >= 58) && (m <= 62)) || (m == 124) )
        {
          flag_Punctuation=1;
	  if(*ch=='!' && lines[i][j+1]=='=')
	  {
	    cout<<25<<'\n';
	    j++;
            flag_Punctuation=0;
	  }
	  if(*ch=='=' && lines[i][j+1]=='=')
	  {
	    cout<<26<<'\n';
	    j++;
            flag_Punctuation=0;
	  }
	  if(*ch=='&' && lines[i][j+1]=='&')
	  {
	    cout<<18<<'\n';
	    j++;
            flag_Punctuation=0;
	  }
	  if(*ch=='|' && lines[i][j+1]=='|')
	  {
	    cout<<19<<'\n';
	    j++;
            flag_Punctuation=0;
	  }
	  if(*ch=='<' && lines[i][j+1]=='=')
	  {
	    cout<<29<<'\n';
	    j++;
            flag_Punctuation=0;
	  }
	  if(*ch=='>' && lines[i][j+1]=='=')
	  {
	    cout<<30<<'\n';
	    j++;
            flag_Punctuation=0;
	  }
	  int mn=(int)lines[i][j+1];
	  if( ((mn >= 65) && (mn <= 90)) || ((mn >= 97) && (mn <= 122)) )
	  {
            mp = T.equal_range(ch);
            for(multimap<string,int>::iterator it = mp.first; it != mp.second; ++it)
            {
              cout<<(*it).second << endl;
            }
	    j++;
            flag_Punctuation=0;
	  }//mn's if loop ends here
        }//Punctuation's if loop ends here
     }//j's for loop ends here

/**************************************************************************/
    if(flag_ResWord==1)
    {
      mp = T.equal_range(cha);
      for(multimap<string,int>::iterator it = mp.first; it != mp.second; ++it)
      {
        cout<<(*it).second << endl;
      }
    }
    if(flag_Variable==1) 
    {
      cout<<32<<endl;
    }
    if(flag_Number==1) 
    {
      cout<<31<<endl;
    } 
    if(flag_Punctuation==1) 
    {
      flag_Punctuation=0;
      mp = T.equal_range(ch);
      for(multimap<string,int>::iterator it = mp.first; it != mp.second; ++it)
      {
        cout<<(*it).second << endl;
      }
    }
  }//i's for loop ends here

  cout<<33<<endl;

  //closing the object for the input and the output files
  istr2.close();
  istr3.close();
  ostr.close();
  ostr2.close();
}//main's loop ends here

/*
void tokenizer::dispResWord(char *ab)
{
      multimap<string,int> T;
      pair<multimap<string,int>::iterator, multimap<string,int>::iterator> mp;
      mp = T.equal_range(ab);
      for(multimap<string,int>::iterator it = mp.first; it != mp.second; ++it)
      {
        cout<<(*it).second << endl;
      }
}

void tokenizer::dispSpeSym(char *cd)
{
}

void tokenizer::dispIntegers(char *ef)
{
}

void tokenizer::dispIdentifiers(char *gh)
{
}

*/
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
