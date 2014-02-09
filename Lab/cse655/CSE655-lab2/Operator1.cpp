{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Operator1.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\cf6 //Expression exp;\cf0 \
\
\cf4 void\cf0  \cf5 Operator1\cf0 ::parseOperator()\
\{\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  \cf4 if\cf0 (curToken==\cf8 31\cf0 )\{\
    altNum=\cf8 1\cf0 ;\
    no=\cf5 t\cf0 .\cf7 intVal\cf0 ();\
    \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  \} \
  \cf4 else\cf0  \cf4 if\cf0 (curToken==\cf8 32\cf0 )\{\
    altNum=\cf8 2\cf0 ;\
    id.\cf7 parseIDForSS\cf0 ();\
  \}\
  \cf4 else\cf0  \cf4 if\cf0 (curToken==\cf8 20\cf0 ) \{\
    altNum=\cf8 3\cf0 ;\
    \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
    exp->\cf7 parseExpression\cf0 ();\
    curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
    \cf4 if\cf0 (curToken != \cf8 21\cf0 )\{\
      cout<<\cf3 "Error-expecting )"\cf0 <<endl;\
      exit(\cf8 0\cf0 );\
    \}\
    \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  \} \
\}\
\
\cf4 void\cf0  \cf5 Operator1\cf0 ::printOperator()\
\{\
  \cf4 if\cf0 (altNum==\cf8 1\cf0 ) \{\
    cout<<no;\
  \} \cf4 else\cf0  \cf4 if\cf0 (altNum==\cf8 2\cf0 ) \{\
      cout<<id.\cf7 getIDName\cf0 ();\
  \} \cf4 else\cf0  \{\
	cout<<\cf3 "("\cf0 ;\
	exp->\cf7 printExpression\cf0 ();\
	cout<<\cf3 ")"\cf0 ;\
    \}\
\}\
\
\cf4 int\cf0  \cf5 Operator1\cf0 ::execOperator()\
\{\
  \cf4 if\cf0 (altNum==\cf8 1\cf0 )\{\
    cout<<no;\
  \} \cf4 else\cf0  \cf4 if\cf0 (altNum==\cf8 2\cf0 ) \{\
      \cf6 //if(!id.getInitialized())\{\cf0 \
	\cf6 //cout<<"Run time error"<<id.getIDName<<" has not been initialized"<<endl;\cf0 \
    	\cf6 //exit(0);\cf0 \
      \cf6 //\}\cf0 \
      \cf4 return\cf0  id.\cf7 getIDVal\cf0 ();\
  \} \cf4 else\cf0  \{\
	\cf4 return\cf0  exp->\cf7 execExpression\cf0 ();\
    \}\
\}\
}