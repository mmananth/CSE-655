/****************************************************************/
/*CSE655-Core-Interpreter                                    	*/
/*Author: Ananth Mahadevan                                   	*/
/*Description: Tokenizer program that tokenizes the input values*/
/****************************************************************/
#include "Tokenizer.h"
#include "Program.h"

/***********************************************************
*Declare the file handler objects
***********************************************************/
Tokenizer::Tokenizer()
{
  k=n=m=0;
  flag_Plus=flag_Equal=flag_LeftParentheses=flag_Semicolon=flag_Num=flag_Upper=flag_Alnum=flag_RightParentheses=flag_Comma=flag_Variable=flag_LeftSquare=flag_RightSquare=0;
}//end of Tokenizer constructor

void Tokenizer::setIndex(int value)
{
  index=value;
}

/***********************************************************
*Declare the file handler objects
***********************************************************/
void Tokenizer::getInput(char* arg1)
{
  istr.open(arg1,ifstream::in);
  if(!istr.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  ostr.open("output1.txt");
  if(!ostr.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  istr2.open("output1.txt", ifstream::in);
  if(!istr2.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  ostr2.open("output2.txt");
  if(!ostr2.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  istr3.open("output2.txt", ifstream::in);
  if(!istr3.is_open()) 
  {
    cout<<"Unable to open file"<<endl;
    exit(1);
  }
  parseToken();
}

/******************************************************************
*Go through the file and get the values into an array.
******************************************************************/
void Tokenizer::parseToken()
{
  count=0;
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
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]=='[') 
	{
	  flag_LeftSquare=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("["), lines[i].length(), " @ ");
	}
      }
      if(flag_LeftSquare==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), "[");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      //------------------------------
      for(int j=0;j<lines[i].size();j++)
      {
	if(lines[i][j]==']') 
	{
	  flag_RightSquare=1;
	  substring1=lines[i].substr(j+1,lines[i].size());
	  lines[i].replace(lines[i].find("]"), lines[i].length(), " @ ");
	}
      }
      if(flag_RightSquare==1)
      {
        for(int j=0;j<lines[i].size();j++)
        {
	  if(lines[i][j]=='@') lines[i].replace(lines[i].find("@"), lines[i].length(), "]");
        }
        lines[i].append(" ");
        lines[i].append(substring1);
      }
      //------------------------------
      flag_Plus=flag_Equal=flag_LeftParentheses=flag_Semicolon=flag_RightParentheses=flag_Comma=flag_LeftSquare=flag_RightSquare=0;
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
}//End of parseToken function

void Tokenizer::skipToken()
{
  index++;
}//end of skipToken method

/************************************************************************************
*This is the section that does the tokenizing of the values in the input file
************************************************************************************/
int Tokenizer::getToken()
{
	flag_Num=flag_Upper=flag_Alnum=flag_Variable=good=0;

	if(lines[index] == "program") {return 1;good=1;}
	if(lines[index] == "begin") {return 2;good=1;}
	if(lines[index] == "end") {return 3;good=1;}
	if(lines[index] == "int") {return 4;good=1;}
	if(lines[index] == "if") {return 5;good=1;}
	if(lines[index] == "then") {return 6;good=1;}
	if(lines[index] == "else") {return 7;good=1;}
	if(lines[index] == "while") {return 8;good=1;}
	if(lines[index] == "loop") {return 9;good=1;}
	if(lines[index] == "read") {return 10;good=1;}
	if(lines[index] == "write") {return 11;good=1;}
	if(lines[index] == ";") {return 12;good=1;}
	if(lines[index] == ",") {return 13;good=1;}
	if(lines[index] == "=") {return 14;good=1;}
	if(lines[index] == "!") {return 15;good=1;}
	if(lines[index] == "[") {return 16;good=1;}
	if(lines[index] == "]") {return 17;good=1;}
	if(lines[index] == "&&") {return 18;good=1;}
	if(lines[index] == "||") {return 19;good=1;}
	if(lines[index] == "(") {return 20;good=1;}
	if(lines[index] == ")") {return 21;good=1;}
	if(lines[index] == "+") {return 22;good=1;}
	if(lines[index] == "-") {return 23;good=1;}
	if(lines[index] == "*") {return 24;good=1;}
	if(lines[index] == "!=") {return 25;good=1;}
	if(lines[index] == "==") {return 26;good=1;}
	if(lines[index] == "<") {return 27;good=1;}
	if(lines[index] == ">") {return 28;good=1;}
	if(lines[index] == "<=") {return 29;good=1;}
	if(lines[index] == ">=") {return 30;good=1;}

	for(int mm=0;mm<lines[index].length();mm++)
	{
		if( (isupper(lines[index][mm-1],loc)) && (isdigit(lines[index][mm],loc)) )
		{ flag_Num=0; }
		else if(isdigit(lines[index][mm],loc)) 
		{ flag_Num=1; }
	}
	if(flag_Num==1) {good=1;return 31;}

	for(int mm=0;mm<lines[index].length();mm++)
	{
		if( ((isupper(lines[index][mm-1],loc)) && (isdigit(lines[index][mm],loc))) || (isupper(lines[index][mm],loc)) )
		{
			if(mm > 9){ good=0; flag_Upper=0; break; }
			flag_Upper=1;
		}
		else if( ((int)(lines[index][mm]) >= 33 && ((int)(lines[index][mm]) <= 47 )) || ((int)(lines[index][mm]) == 58) || ((int)(lines[index][mm]) == 63) || ((int)(lines[index][mm]) == 64) )
		{ flag_Upper=0; good=0; break; }
	}
	if(flag_Upper==1) {good=1;return 32;}

	if(index==count) {
		good=1;
		return 33;
	}

	if(index>count) good=1; //for stopping the program since index will be greater than count
	if(good==0) return -1;

	//closing the object for the input and the output files
	istr2.close();
	istr3.close();
	ostr.close();
	ostr2.close();
}//getToken's loop ends here

void Tokenizer::printLines()
{
  cout<<lines[index]<<endl;
}

string Tokenizer::getIdName()
{
  return lines[index];
}

string Tokenizer::intVal()
{
  return lines[index];
}
