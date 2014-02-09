#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<locale>
#include "Core.cpp"

using namespace std;


/*int main(int argc, char* argv[])
{
  Tokenizer t;
  t.getToken(argv[1]);
}*/


public class Tokenizer
{
Tokenizer();
/*public:
  void skipToken();
  void intVal();
  void idName();*/

public int getToken(char* arg1)
{
  locale loc;
  string lines[1000],line,lines1[1000],line1,lineCnt,substring1;
  char *ch, *chra, *cha, *cstr, *cstra, *pt, *pt1, *pta, c, *cstr1;

  size_t found;
  int k=0,n=0,count=0,count1=0,m=0;
  int flag_Plus=0, flag_Equal=0, flag_LeftParentheses=0, flag_Semicolon=0, flag_Num=0, flag_Upper=0, flag_Alnum=0, flag_RightParentheses=0, flag_Comma=0, flag_Variable=0;

/***********************************************************
*Declare the file handler objects
***********************************************************/
  ifstream istr(arg1);
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
	  lines[i].replace(lines[i].find("+"), lines[i].length(), " @ ");
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
      //------------------------------
      for(int j=0;j<lines[i].size();j++)
      {
        if( (lines[i][j] == '=') && (lines[i][j+1] == '=') && (lines[i][j+2] == '=') )
        {
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("="), lines[i].length(), " =");
	  lines[i].append(" ");
          lines[i].append(substring1);
        }
        else if( (lines[i][j] == '=') && (lines[i][j-1] == '=') )
        {
          if( (((int)lines[i][j+1] >= 48) && ((int)lines[i][j+1] <= 57)) || (((int)lines[i][j+1] >= 65) && ((int)lines[i][j+1] <= 90)) )
          {
	    substring1=lines[i].substr(j+1,lines[i].size());
	    lines[i].replace(lines[i].find("=="), lines[i].length(), " ==");
	    lines[i].append(" ");
            lines[i].append(substring1);
	  }
	}
	if( (lines[i][j] == '=') && (lines[i][j-1] == '=') )
	{
	  flag_Equal=0;
	}
	else if( (lines[i][j] == '=') && (lines[i][j-1] == '!') )
	{
	  flag_Equal=0;
	}
	else if( (lines[i][j] == '=') && (lines[i][j-1] == '<') )
	{
	  flag_Equal=0;
	}
	else if( (lines[i][j] == '=') && (lines[i][j-1] == '>') )
	{
	  flag_Equal=0;
	}
	else if(lines[i][j] == '=')
	{
          if( (((int)lines[i][j+1] >= 48) && ((int)lines[i][j+1] <= 57)) || (((int)lines[i][j+1] >= 65) && ((int)lines[i][j+1] <= 90)) )
          {
	    substring1=lines[i].substr(j+1,lines[i].size());
	    lines[i].replace(lines[i].find("="), lines[i].length(), " =");
	    lines[i].append(" ");
            lines[i].append(substring1);
	  }
	}
      }

      //------------------------------
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]=='(') 
	{
	  flag_LeftParentheses=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("("), lines[i].length(), " @ ");
	}
      }
      if(flag_LeftParentheses==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), "(");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      //------------------------------
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]==';') 
	{
	  flag_Semicolon=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find(";"), lines[i].length(), " @ ");
	}
      }
      if(flag_Semicolon==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), ";");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      //------------------------------
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]==')') 
	{
	  flag_RightParentheses=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find(")"), lines[i].length(), " @ ");
	}
      }
      if(flag_RightParentheses==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), ")");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      //------------------------------
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]==',') 
	{
	  flag_Comma=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find(","), lines[i].length(), " @ ");
	}
      }
      if(flag_Comma==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), ",");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      //------------------------------
      flag_Plus=flag_Equal=flag_LeftParentheses=flag_Semicolon=flag_RightParentheses=flag_Comma=0;
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
      flag_Num=flag_Upper=flag_Alnum=flag_Variable=0;

      for(int mm=0;mm<lines[i].length();mm++)
      {
        //if( ((isupper(lines[i][mm],loc)) && (isdigit(lines[i][mm+1]))) || ((isdigit(lines[i][mm],loc)) && (isupper(lines[i][mm+1]))) ) 
        if( (isdigit(lines[i][mm],loc)) && (isupper(lines[i][mm+1])) ) 
        {
	  cout<<"Error in input"<<endl;
	}
      }

      if(lines[i] == "program") cout<<"1"<<endl;
      if(lines[i] == "begin") cout<<"2"<<endl;
      if(lines[i] == "end") cout<<"3"<<endl;
      if(lines[i] == "int") cout<<"4"<<endl;
      if(lines[i] == "if") cout<<"5"<<endl;
      if(lines[i] == "then") cout<<"6"<<endl;
      if(lines[i] == "else") cout<<"7"<<endl;
      if(lines[i] == "while") cout<<"8"<<endl;
      if(lines[i] == "loop") cout<<"9"<<endl;
      if(lines[i] == "read") cout<<"10"<<endl;
      if(lines[i] == "write") cout<<"11"<<endl;
      if(lines[i] == ";") cout<<"12"<<endl;
      if(lines[i] == ",") cout<<"13"<<endl;
      if(lines[i] == "=") cout<<"14"<<endl;
      if(lines[i] == "!") cout<<"15"<<endl;
      if(lines[i] == "[") cout<<"16"<<endl;
      if(lines[i] == "]") cout<<"17"<<endl;
      if(lines[i] == "&&") cout<<"18"<<endl;
      if(lines[i] == "||") cout<<"19"<<endl;
      if(lines[i] == "(") cout<<"20"<<endl;
      if(lines[i] == ")") cout<<"21"<<endl;
      if(lines[i] == "+") cout<<"22"<<endl;
      if(lines[i] == "-") cout<<"23"<<endl;
      if(lines[i] == "*") cout<<"24"<<endl;
      if(lines[i] == "!=") cout<<"25"<<endl;
      if(lines[i] == "==") cout<<"26"<<endl;
      if(lines[i] == "<") cout<<"27"<<endl;
      if(lines[i] == ">") cout<<"28"<<endl;
      if(lines[i] == "<=") cout<<"29"<<endl;
      if(lines[i] == ">=") cout<<"30"<<endl;

      for(int mm=0;mm<lines[i].length();mm++)
      {
	if( (isupper(lines[i][mm-1],loc)) && (isdigit(lines[i][mm],loc)) )
        {
	  flag_Num=0;
	}
        else if(isdigit(lines[i][mm],loc)) 
        {
	  flag_Num=1;
        }
      }
      if(flag_Num==1) cout<<"31"<<endl;
	
      for(int mm=0;mm<lines[i].length();mm++)
      {
        if( ((isupper(lines[i][mm-1],loc)) && (isdigit(lines[i][mm],loc))) || (isupper(lines[i][mm],loc)) )
        {
	  flag_Upper=1;
        }
	else 
	{
	  flag_Upper=0;
	}
      }
      if(flag_Upper==1) cout<<"32"<<endl;

  }//i's for loop ends here

  cout<<33<<endl;

  //closing the object for the input and the output files
  istr2.close();
  istr3.close();
  ostr.close();
  ostr2.close();
  //Core();
}//main's loop ends here
}
