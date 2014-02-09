{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red28\green0\blue207;\red0\green116\blue0;\red38\green71\blue75;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Program.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf4 void\cf0  \cf5 Program\cf0 ::parseInputFile2(\cf4 char\cf0 * arg2) \{\
  countFile2=\cf6 0\cf0 ;\
  ifstr.open(arg2,ifstream::in);\
  \cf4 if\cf0 (!ifstr.is_open())\
  \{\
    cout<<\cf3 "Unable to open file "\cf0 <<endl;\
    exit(\cf6 1\cf0 );\
  \}\
\
  \cf4 while\cf0 (getline(ifstr,lineFile2)) \{\
    linesFile2[countFile2++]=lineFile2;\
  \}\
  ifstr.close();\
\
  \cf4 int\cf0  u=\cf6 0\cf0 ;\
  cstr2=\cf4 new\cf0  \cf4 char\cf0 [\cf6 100\cf0 ];\
  \cf4 for\cf0 (\cf4 int\cf0  i=\cf6 0\cf0 ;i<countFile2;i++)\
  \{\
    strcpy(cstr2,linesFile2[i].c_str());\
    pt2=strtok(cstr2,\cf3 " \\t"\cf0 );\
    \cf4 while\cf0 (pt2!=\cf4 NULL\cf0 )\
    \{\
      linesFile2[u++]=pt2;\
      pt2=strtok(\cf4 NULL\cf0 ,\cf3 " \\t"\cf0 );\
    \}\
  \}\
\
  cout<<\cf3 "Output of Inputfile 2"\cf0 <<endl;\
  \cf4 for\cf0 (\cf4 int\cf0  i=\cf6 0\cf0 ;i<=countFile2;i++)\
    cout<<linesFile2[i]<<\cf3 " "\cf0 <<endl;\
\}\
\
\cf4 int\cf0  \cf5 Program\cf0 ::getNextInputVal()\
\{\
  \cf7 //return linesFile2[index2];\cf0 \
  \cf7 //index2++;\cf0 \
    \cf4 return\cf0  \cf6 0\cf0 ;\
\}\
\
\cf7 /*******************************************************************/\cf0 \
\
\cf4 void\cf0  \cf5 Program\cf0 ::parseProgram() \{\
    \cf5 t\cf0 .\cf8 setIndex\cf0 (-\cf6 1\cf0 );\
    \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
    curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
    \cf7 //----------------------------------------------------------------//\cf0 \
    \cf4 if\cf0 (curToken == \cf6 1\cf0 ) \{\
      \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
      curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      \cf4 while\cf0 (curToken != \cf6 2\cf0 ) \{\
        ds.\cf8 parseDS\cf0 (); \
        \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
        curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      \}\
    \}\
    \cf4 else\cf0  \{\
      cout<<\cf3 "error 1"\cf0 <<endl;\
      exit(\cf6 1\cf0 );\
    \}\
    cout<<endl;\
    \cf7 //----------------------------------------------------------------\cf0 \
    \cf4 if\cf0 (curToken == \cf6 2\cf0 ) \{\
      \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
      curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      \cf4 while\cf0 (curToken != \cf6 3\cf0 ) \{\
        ss.\cf8 parseSS\cf0 (); \
        \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
        curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      \}\
    \}\
    \cf4 else\cf0  \{\
      cout<<\cf3 "error 2"\cf0 <<endl;\
      exit(\cf6 1\cf0 );\
    \}\
    cout<<endl;\
    \cf7 //----------------------------------------------------------------//\cf0 \
    \cf4 if\cf0 (curToken == \cf6 3\cf0 ) \{\
      \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
      curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      cout<<\cf3 "End of Parsing. No errors found"\cf0 <<endl;\
    \}\
    \cf4 else\cf0  \{\
      cout<<\cf3 "error 3"\cf0 <<endl;\
      exit(\cf6 1\cf0 );\
    \}\
\}\
\
\cf7 /*******************************************************************/\cf0 \
\
\cf4 void\cf0  \cf5 Program\cf0 ::printProgram() \{\
    \cf5 t\cf0 .\cf8 setIndex\cf0 (-\cf6 1\cf0 );\
    \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
    curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
    \cf7 //----------------------------------------------------------------//\cf0 \
    \cf4 if\cf0 (curToken == \cf6 1\cf0 ) \{\
      cout<<\cf3 "program"\cf0 <<endl;\
      \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
      \cf4 while\cf0 (curToken != \cf6 2\cf0 ) \{\
        ds.\cf8 printDS\cf0 ();\
	\cf5 t\cf0 .\cf8 skipToken\cf0 ();\
	curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      \}\
    \}\
    \cf4 else\cf0  \{\
      cout<<\cf3 "error 1"\cf0 <<endl;\
      exit(\cf6 1\cf0 );\
    \}\
    cout<<endl;\
    \cf7 //----------------------------------------------------------------//\cf0 \
    \cf4 if\cf0 (curToken == \cf6 2\cf0 ) \{\
      cout<<\cf3 "begin"\cf0 <<endl;\
      id.\cf8 insertSpace\cf0 ();\
      \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
      \cf4 while\cf0 (curToken != \cf6 3\cf0 ) \{\
        ss.\cf8 printSS\cf0 ();\
 	\cf5 t\cf0 .\cf8 skipToken\cf0 ();\
	curToken=\cf5 t\cf0 .\cf8 getToken\cf0 ();\
      \}\
    \}\
    \cf4 else\cf0  \{\
      cout<<\cf3 "error 2"\cf0 <<endl;\
      exit(\cf6 1\cf0 );\
    \}\
    cout<<endl;\
    \cf7 //----------------------------------------------------------------//\cf0 \
    \cf4 if\cf0 (curToken == \cf6 3\cf0 ) \{\
      cout<<\cf3 "end"\cf0 <<endl;\
    \}\
    \cf4 else\cf0  \{\
      cout<<\cf3 "error 3"\cf0 <<endl;\
    \}\
\}\
\
\cf7 /*******************************************************************/\cf0 \
\
\cf4 void\cf0  \cf5 Program\cf0 ::execProgram() \{\
    ss.\cf8 execSS\cf0 ();\
\}\
}