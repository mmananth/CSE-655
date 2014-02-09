{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;\red28\green0\blue207;\red38\green71\blue75;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "ID.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf6 //static int idCount=0;\cf0 \
\cf4 static\cf0  \cf5 ID\cf0 * \cf5 eIDs\cf0 [\cf7 20\cf0 ];\
\cf4 static\cf0  \cf4 int\cf0  \cf5 idCount\cf0  = \cf7 0\cf0 ;\
\
\cf5 ID\cf0 * \cf5 ID\cf0 ::parseIDForDS()\
\{\
    string idName=\cf5 t\cf0 .\cf8 getIdName\cf0 ();\
    \cf4 for\cf0 (\cf4 int\cf0  k=\cf7 0\cf0 ; k<\cf5 idCount\cf0 ; k++)\
    \{\
      \cf4 if\cf0 (idName==\cf5 eIDs\cf0 [k]->\cf5 name\cf0 ) \{\
	cout<<\cf3 "Error - variable has already been declared"\cf0 <<endl;\
	exit(\cf7 0\cf0 );\
      \}\
        \cf5 ID\cf0  *nID = \cf4 new\cf0  \cf5 ID\cf0 (idName);\
        \cf5 eIDs\cf0 [\cf5 idCount\cf0 ++]=nID;\
        \cf4 return\cf0  nID;\
    \}\
\}\
\
\cf5 ID\cf0 * \cf5 ID\cf0 ::parseIDForSS()\
\{\
    string idName=\cf5 t\cf0 .\cf8 getIdName\cf0 ();\
    \cf4 for\cf0 (\cf4 int\cf0  k=\cf7 0\cf0 ; k<\cf5 idCount\cf0 ; k++)\
    \{\
      \cf4 if\cf0 (idName==\cf5 eIDs\cf0 [k]->\cf5 name\cf0 ) \{\
        \cf5 t\cf0 .\cf8 skipToken\cf0 ();\
        \cf4 return\cf0  \cf5 eIDs\cf0 [k];\
      \}\
        \cf6 //ID nID(idName);\cf0 \
        \cf6 //eIDs[idCount++]=nID;\cf0 \
        \cf6 //return nID;\cf0 \
    \}\
    cout<<\cf3 "Error - variable has already been declared"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
\}\
\
\cf6 /*void ID::printID()\
\{\
  curToken=t.getToken();\
  if(curToken == 4) \{\
    insertSpace();\
    insertSpace();\
  \}\
  else if(curToken == 5) \{\
    cout<<endl;\
    insertSpace();\
    insertSpace();\
  \}\
  else if(curToken == 6) \{\
    insertSpace();\
    insertSpace();\
  \}\
  else if(curToken == 8) \{\
    cout<<endl;\
    insertSpace();\
    insertSpace();\
  \}\
  else if(curToken == 9) \{\
    insertSpace();\
    insertSpace();\
  \}\
  else if(curToken == 10) \{\
    insertSpace();\
    insertSpace();\
  \}\
  else if(curToken == 11) \{\
    insertSpace();\
    insertSpace();\
  \}\
  else if( (curToken != 12) && (curToken != 13) && (curToken != 15) && (curToken != 16) && (curToken != 17) && (curToken !=20) && (curToken != 21) && (curToken != 27) && (curToken != 28) )\
  \{\
    insertSpace();\
  \}\
    t.printLines();\
\}*/\cf0 \
\
\cf4 void\cf0  \cf5 ID\cf0 ::insertSpace()\
\{\
  cout<<\cf3 " "\cf0 ;\
\}\
\
string \cf5 ID\cf0 ::getIDName()\
\{\
\}\
\
\cf4 void\cf0  \cf5 ID\cf0 ::setIDVal(\cf4 int\cf0 )\
\{\
\}\
\
\cf4 int\cf0  \cf5 ID\cf0 ::getIDVal()\
\{\
\}\
}