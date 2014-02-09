{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red0\green116\blue0;
\red63\green110\blue116;\red28\green0\blue207;\red170\green13\blue145;\red38\green71\blue75;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Program.h"\cf2 \
#include \cf3 "Tokenizer.h"\cf2 \
\cf0 \
\cf4 /***********************************************************\
*Declare the file handler objects\
***********************************************************/\cf0 \
\cf5 Tokenizer\cf0 ::\cf5 Tokenizer\cf0 ()\
\{\
  k=n=m=\cf6 0\cf0 ;\
  flag_Plus=flag_Equal=flag_LeftParentheses=flag_Semicolon=flag_Num=flag_Upper=flag_Alnum=flag_RightParentheses=flag_Comma=flag_Variable=flag_LeftSquare=flag_RightSquare=\cf6 0\cf0 ;\
  \cf4 //index=-1;\cf0 \
\}\cf4 //end of Tokenizer constructor\cf0 \
\
\cf7 void\cf0  \cf5 Tokenizer\cf0 ::setIndex(\cf7 int\cf0  value)\
\{\
  index=value;\
\}\
\
\cf7 void\cf0  \cf5 Tokenizer\cf0 ::getInput(\cf7 char\cf0 * arg1)\
\{\
  istr.open(arg1,ifstream::in);\
  \cf7 if\cf0 (!istr.is_open()) \
  \{\
    cout<<\cf3 "Unable to open file"\cf0 <<endl;\
    exit(\cf6 1\cf0 );\
  \}\
  ostr.open(\cf3 "output1.txt"\cf0 );\
  \cf7 if\cf0 (!ostr.is_open()) \
  \{\
    cout<<\cf3 "Unable to open file"\cf0 <<endl;\
    exit(\cf6 1\cf0 );\
  \}\
  istr2.open(\cf3 "output1.txt"\cf0 , ifstream::in);\
  \cf7 if\cf0 (!istr2.is_open()) \
  \{\
    cout<<\cf3 "Unable to open file"\cf0 <<endl;\
    exit(\cf6 1\cf0 );\
  \}\
  ostr2.open(\cf3 "output2.txt"\cf0 );\
  \cf7 if\cf0 (!ostr2.is_open()) \
  \{\
    cout<<\cf3 "Unable to open file"\cf0 <<endl;\
    exit(\cf6 1\cf0 );\
  \}\
  istr3.open(\cf3 "output2.txt"\cf0 , ifstream::in);\
  \cf7 if\cf0 (!istr3.is_open()) \
  \{\
    cout<<\cf3 "Unable to open file"\cf0 <<endl;\
    exit(\cf6 1\cf0 );\
  \}\
  \cf8 parseToken\cf0 ();\
\}\
\
\cf4 /******************************************************************\
*Go through the file and get the values into an array.\
******************************************************************/\cf0 \
\cf7 void\cf0  \cf5 Tokenizer\cf0 ::parseToken()\
\{\
  count=\cf6 0\cf0 ;\
  \cf7 while\cf0 (getline(istr,line))\
  \{\
    lines[count++]=line;\
  \}\
\
  \cf4 //closing the object for the input file\cf0 \
  istr.close();\
\
\cf4 /************************************************************************************\
*Use the string tokenizer function to get the tokens with space and tab as delimiters\
************************************************************************************/\cf0 \
  cstr=\cf7 new\cf0  \cf7 char\cf0 [\cf6 1000\cf0 ];\
  \cf7 for\cf0 (\cf7 int\cf0  i=\cf6 0\cf0 ;i<count;i++)\
  \{\
    strcpy(cstr,lines[i].c_str());\
    pt=strtok(cstr,\cf3 " \\t"\cf0 );\
    \cf7 while\cf0 (pt!=\cf7 NULL\cf0 )\
    \{\
      ostr<<pt<<endl;\
      pt=strtok(\cf7 NULL\cf0 ,\cf3 " \\t"\cf0 );\
    \}\
  \}\
\
  count = \cf6 0\cf0 ;\
  \cf7 while\cf0 (getline(istr2,line)) lines[count++]=line;\
\
\cf4 /************************************************************************************\
*Manipulation of certain special symbols so that tokenizing becomes easier\
************************************************************************************/\cf0 \
  \cf7 for\cf0 (\cf7 int\cf0  i=\cf6 0\cf0 ;i<count;i++)\
  \{\
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 '+'\cf0 ) \
	\{\
	  flag_Plus=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 "+"\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_Plus==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 "+"\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
        \cf7 if\cf0 ( (lines[i][j] == \cf6 '='\cf0 ) && (lines[i][j+\cf6 1\cf0 ] == \cf6 '='\cf0 ) && (lines[i][j+\cf6 2\cf0 ] == \cf6 '='\cf0 ) )\
        \{\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 "="\cf0 ), lines[i].length(), \cf3 " ="\cf0 );\
	  lines[i].append(\cf3 " "\cf0 );\
          lines[i].append(substring1);\
        \}\
        \cf7 else\cf0  \cf7 if\cf0 ( (lines[i][j] == \cf6 '='\cf0 ) && (lines[i][j-\cf6 1\cf0 ] == \cf6 '='\cf0 ) )\
        \{\
          \cf7 if\cf0 ( (((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] >= \cf6 48\cf0 ) && ((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] <= \cf6 57\cf0 )) || (((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] >= \cf6 65\cf0 ) && ((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] <= \cf6 90\cf0 )) )\
          \{\
	    substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	    lines[i].replace(lines[i].find(\cf3 "=="\cf0 ), lines[i].length(), \cf3 " =="\cf0 );\
	    lines[i].append(\cf3 " "\cf0 );\
            lines[i].append(substring1);\
	  \}\
	\}\
	\cf7 if\cf0 ( (lines[i][j] == \cf6 '='\cf0 ) && (lines[i][j-\cf6 1\cf0 ] == \cf6 '='\cf0 ) )\
	\{\
	  flag_Equal=\cf6 0\cf0 ;\
	\}\
	\cf7 else\cf0  \cf7 if\cf0 ( (lines[i][j] == \cf6 '='\cf0 ) && (lines[i][j-\cf6 1\cf0 ] == \cf6 '!'\cf0 ) )\
	\{\
	  flag_Equal=\cf6 0\cf0 ;\
	\}\
	\cf7 else\cf0  \cf7 if\cf0 ( (lines[i][j] == \cf6 '='\cf0 ) && (lines[i][j-\cf6 1\cf0 ] == \cf6 '<'\cf0 ) )\
	\{\
	  flag_Equal=\cf6 0\cf0 ;\
	\}\
	\cf7 else\cf0  \cf7 if\cf0 ( (lines[i][j] == \cf6 '='\cf0 ) && (lines[i][j-\cf6 1\cf0 ] == \cf6 '>'\cf0 ) )\
	\{\
	  flag_Equal=\cf6 0\cf0 ;\
	\}\
	\cf7 else\cf0  \cf7 if\cf0 (lines[i][j] == \cf6 '='\cf0 )\
	\{\
          \cf7 if\cf0 ( (((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] >= \cf6 48\cf0 ) && ((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] <= \cf6 57\cf0 )) || (((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] >= \cf6 65\cf0 ) && ((\cf7 int\cf0 )lines[i][j+\cf6 1\cf0 ] <= \cf6 90\cf0 )) )\
          \{\
	    substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	    lines[i].replace(lines[i].find(\cf3 "="\cf0 ), lines[i].length(), \cf3 " ="\cf0 );\
	    lines[i].append(\cf3 " "\cf0 );\
            lines[i].append(substring1);\
	  \}\
	\}\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 '('\cf0 ) \
	\{\
	  flag_LeftParentheses=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 "("\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_LeftParentheses==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 "("\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 ';'\cf0 ) \
	\{\
	  flag_Semicolon=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 ";"\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_Semicolon==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 ";"\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 ')'\cf0 ) \
	\{\
	  flag_RightParentheses=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 ")"\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_RightParentheses==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 ")"\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 ','\cf0 ) \
	\{\
	  flag_Comma=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 ","\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_Comma==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 ","\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 '['\cf0 ) \
	\{\
	  flag_LeftSquare=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 "["\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_LeftSquare==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 "["\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
      \{\
	\cf7 if\cf0 (lines[i][j]==\cf6 ']'\cf0 ) \
	\{\
	  flag_RightSquare=\cf6 1\cf0 ;\
	  substring1=lines[i].substr(j+\cf6 1\cf0 ,lines[i].size());\
	  lines[i].replace(lines[i].find(\cf3 "]"\cf0 ), lines[i].length(), \cf3 " @ "\cf0 );\
	\}\
      \}\
      \cf7 if\cf0 (flag_RightSquare==\cf6 1\cf0 )\
      \{\
        \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<lines[i].size();j++)\
        \{\
	  \cf7 if\cf0 (lines[i][j]==\cf6 '@'\cf0 ) lines[i].replace(lines[i].find(\cf3 "@"\cf0 ), lines[i].length(), \cf3 "]"\cf0 );\
        \}\
        lines[i].append(\cf3 " "\cf0 );\
        lines[i].append(substring1);\
      \}\
      \cf4 //------------------------------\cf0 \
      flag_Plus=flag_Equal=flag_LeftParentheses=flag_Semicolon=flag_RightParentheses=flag_Comma=flag_LeftSquare=flag_RightSquare=\cf6 0\cf0 ;\
  \}\
\
\cf4 /************************************************************************************\
*Further manipulation\
************************************************************************************/\cf0 \
      cstra=\cf7 new\cf0  \cf7 char\cf0 [\cf6 1000\cf0 ];\
      \cf7 for\cf0 (\cf7 int\cf0  j=\cf6 0\cf0 ;j<count;j++)\
      \{\
 	strcpy(cstra,lines[j].c_str());\
	pta=strtok(cstra,\cf3 " \\t"\cf0 );\
	\cf7 while\cf0 (pta!=\cf7 NULL\cf0 )\
	\{\
	  ostr2<<pta<<endl;;\
	  pta=strtok(\cf7 NULL\cf0 ,\cf3 " \\t"\cf0 );\
	\}\
      \}\
\
  count = \cf6 0\cf0 ;\
  \cf7 while\cf0 (getline(istr3,line)) lines[count++]=line;\
  \cf4 //skipToken();\cf0 \
  \cf4 //tokenDone=1;\cf0 \
\cf4 //\}\cf0 \
\}\cf4 //End of parseToken function\cf0 \
\
\cf7 void\cf0  \cf5 Tokenizer\cf0 ::skipToken()\
\{\
  index++;\
\}\cf4 //end of skipToken method\cf0 \
\
\cf4 /************************************************************************************\
*This is the section that does the tokenizing of the values in the input file\
************************************************************************************/\cf0 \
\cf7 int\cf0  \cf5 Tokenizer\cf0 ::getToken()\
\{\
	flag_Num=flag_Upper=flag_Alnum=flag_Variable=good=\cf6 0\cf0 ;\
	\cf4 //cout<<"index in getToken "<<index<<endl;\cf0 \
  	\cf4 //cout<<"count in getToken "<<count<<endl;\cf0 \
\
	\cf7 if\cf0 (lines[index] == \cf3 "program"\cf0 ) \{\cf7 return\cf0  \cf6 1\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "begin"\cf0 ) \{\cf7 return\cf0  \cf6 2\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "end"\cf0 ) \{\cf7 return\cf0  \cf6 3\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "int"\cf0 ) \{\cf7 return\cf0  \cf6 4\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "if"\cf0 ) \{\cf7 return\cf0  \cf6 5\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "then"\cf0 ) \{\cf7 return\cf0  \cf6 6\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "else"\cf0 ) \{\cf7 return\cf0  \cf6 7\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "while"\cf0 ) \{\cf7 return\cf0  \cf6 8\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "loop"\cf0 ) \{\cf7 return\cf0  \cf6 9\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "read"\cf0 ) \{\cf7 return\cf0  \cf6 10\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "write"\cf0 ) \{\cf7 return\cf0  \cf6 11\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 ";"\cf0 ) \{\cf7 return\cf0  \cf6 12\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 ","\cf0 ) \{\cf7 return\cf0  \cf6 13\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "="\cf0 ) \{\cf7 return\cf0  \cf6 14\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "!"\cf0 ) \{\cf7 return\cf0  \cf6 15\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "["\cf0 ) \{\cf7 return\cf0  \cf6 16\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "]"\cf0 ) \{\cf7 return\cf0  \cf6 17\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "&&"\cf0 ) \{\cf7 return\cf0  \cf6 18\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "||"\cf0 ) \{\cf7 return\cf0  \cf6 19\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "("\cf0 ) \{\cf7 return\cf0  \cf6 20\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 ")"\cf0 ) \{\cf7 return\cf0  \cf6 21\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "+"\cf0 ) \{\cf7 return\cf0  \cf6 22\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "-"\cf0 ) \{\cf7 return\cf0  \cf6 23\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "*"\cf0 ) \{\cf7 return\cf0  \cf6 24\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "!="\cf0 ) \{\cf7 return\cf0  \cf6 25\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "=="\cf0 ) \{\cf7 return\cf0  \cf6 26\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "<"\cf0 ) \{\cf7 return\cf0  \cf6 27\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 ">"\cf0 ) \{\cf7 return\cf0  \cf6 28\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 "<="\cf0 ) \{\cf7 return\cf0  \cf6 29\cf0 ;good=\cf6 1\cf0 ;\}\
	\cf7 if\cf0 (lines[index] == \cf3 ">="\cf0 ) \{\cf7 return\cf0  \cf6 30\cf0 ;good=\cf6 1\cf0 ;\}\
\
	\cf7 for\cf0 (\cf7 int\cf0  mm=\cf6 0\cf0 ;mm<lines[index].length();mm++)\
	\{\
		\cf7 if\cf0 ( (isupper(lines[index][mm-\cf6 1\cf0 ],loc)) && (isdigit(lines[index][mm],loc)) )\
		\{ flag_Num=\cf6 0\cf0 ; \}\
		\cf7 else\cf0  \cf7 if\cf0 (isdigit(lines[index][mm],loc)) \
		\{ flag_Num=\cf6 1\cf0 ; \}\
	\}\
	\cf7 if\cf0 (flag_Num==\cf6 1\cf0 ) \{good=\cf6 1\cf0 ;\cf7 return\cf0  \cf6 31\cf0 ;\}\
\
	\cf7 for\cf0 (\cf7 int\cf0  mm=\cf6 0\cf0 ;mm<lines[index].length();mm++)\
	\{\
		\cf7 if\cf0 ( ((isupper(lines[index][mm-\cf6 1\cf0 ],loc)) && (isdigit(lines[index][mm],loc))) || (isupper(lines[index][mm],loc)) )\
		\{\
			\cf7 if\cf0 (mm > \cf6 9\cf0 )\{ good=\cf6 0\cf0 ; flag_Upper=\cf6 0\cf0 ; \cf7 break\cf0 ; \}\
			flag_Upper=\cf6 1\cf0 ;\
		\}\
		\cf7 else\cf0  \cf7 if\cf0 ( ((\cf7 int\cf0 )(lines[index][mm]) >= \cf6 33\cf0  && ((\cf7 int\cf0 )(lines[index][mm]) <= \cf6 47\cf0  )) || ((\cf7 int\cf0 )(lines[index][mm]) == \cf6 58\cf0 ) || ((\cf7 int\cf0 )(lines[index][mm]) == \cf6 63\cf0 ) || ((\cf7 int\cf0 )(lines[index][mm]) == \cf6 64\cf0 ) )\
		\{ flag_Upper=\cf6 0\cf0 ; good=\cf6 0\cf0 ; \cf7 break\cf0 ; \}\
	\}\
	\cf7 if\cf0 (flag_Upper==\cf6 1\cf0 ) \{good=\cf6 1\cf0 ;\cf7 return\cf0  \cf6 32\cf0 ;\}\
\
	\cf4 /*if((index==count) && (lines[index-3] == "end"))\
	\{\
		good=1; return -2;\
	\}\
	else if(index==count) \{*/\cf0 \
	\cf7 if\cf0 (index==count) \{\
		good=\cf6 1\cf0 ;\
		\cf7 return\cf0  \cf6 33\cf0 ;\
	\}\
	\cf4 //else if(lines[index-3] == "end") \{ return -1; good=1; \}\cf0 \
\
	\cf7 if\cf0 (index>count) good=\cf6 1\cf0 ; \cf4 //for stopping the program since index will be greater than count\cf0 \
	\cf7 if\cf0 (good==\cf6 0\cf0 ) \cf7 return\cf0  -\cf6 1\cf0 ;\
\
	\cf4 //closing the object for the input and the output files\cf0 \
	istr2.close();\
	istr3.close();\
	ostr.close();\
	ostr2.close();\
\}\cf4 //getToken's loop ends here\cf0 \
\
\cf7 void\cf0  \cf5 Tokenizer\cf0 ::printLines()\
\{\
  cout<<lines[index]<<endl;\
\}\
\
string \cf5 Tokenizer\cf0 ::getIdName()\
\{\
  \cf7 return\cf0  lines[index];\
\}\
\
\cf7 int\cf0  \cf5 Tokenizer\cf0 ::intVal()\
\{\
  \cf7 return\cf0  index;\
\}\
}