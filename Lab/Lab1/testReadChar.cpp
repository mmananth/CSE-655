#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std;

int main()
{
  locale loc;
  int count=0,counta=0,k=0,m=0;
  int flag_ResWord=0, flag_Variable=0, flag_Number=0, flag_Punctuation=0, flag_Alphanumeric=0,flag_alphaFirstPass=0,flag_numberFirstPass=0;
  ifstream istr("sample4.txt");
  ofstream ostr("output4.txt");
  ifstream istr2("output4.txt");
  string line,lines[200],linea,linesa[200];
  char c;
  char * cstr, *p;

  while(getline(istr,line))
    lines[count++]=line;

  istr.close();

  cstr=new char[count];
  for(int i=0;i<count;i++)
  {
    strcpy(cstr,lines[i].c_str());
    p=strtok(cstr," \t");
    while(p!=NULL)
    {
      ostr<<p<<endl;
      p=strtok(NULL," ");
    }
  }

  count = 0;
  while(getline(istr2,line)) lines[count++]=line;

  for(int i=0;i<count;i++)
  {
    flag_ResWord=flag_Variable=flag_Alphanumeric=flag_Number=flag_Punctuation=flag_alphaFirstPass=flag_numberFirstPass=0;
    for(int j=0;j<lines[i].size();j++)
    {
    c=lines[i][j];
    m=(int)c;


      if( ((m >= 65) && (m <= 90)) || ((m >= 97) && (m <= 122)) || ( flag_alphaFirstPass==1 && ((m >=48) && (m <= 57))) )
      {
	flag_alphaFirstPass=1;
        if( (m >= 97) && (m <= 122) )
        {
	  flag_ResWord=1;
	  cout<< c <<endl;
        }
        else if( (m >= 65) && (m <= 90) )
        {
	  flag_Variable=1;
	  cout<< c <<endl;
        }
	else if( (m >= 48) && (m <= 57) )
	{
	  flag_Alphanumeric=1;
	  flag_ResWord=flag_Variable=flag_Number=flag_alphaFirstPass=0;
	  cout<<"error"<<endl;
	  break;
	}
      }
      
      if( ((m >=48) && (m <= 57)) || ( flag_numberFirstPass==1 && (((m >= 65) && (m <= 90)) || ((m >= 97) && (m <= 122)))) )
      {
	flag_numberFirstPass=1;
	if( (m >= 48) && (m <= 57) )
	{
  	  flag_Number=1;
	  cout<< c << endl;
	}
	else if( ((m >= 65) && (m <= 90)) || ((m >= 97) && (m <= 122)) )
	{
	  flag_Alphanumeric=1;
	  flag_ResWord=flag_Variable=flag_Number=flag_numberFirstPass=0;
	  cout<<"error"<<endl;
	  break;
	}
      }

      if( ((m >= 33) && (m <= 47)) || ((m >= 58) && (m <= 62)) )
      {
	flag_Punctuation=1;
	cout<< c <<endl;
      }
    }
  if(flag_ResWord==1) cout<<"calling Res word"<<endl;
  if(flag_Variable==1) cout<<"calling variable"<<endl;
  if(flag_Number==1) cout<<"calling number"<<endl;
  if(flag_Punctuation==1) cout<<"calling punctuation"<<endl;
  } 

  istr2.close();
}
