{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red28\green0\blue207;\red38\green71\blue75;\red0\green116\blue0;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Assign.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf4 int\cf0  \cf5 resultAssign\cf0 =\cf6 0\cf0 ;\
\cf4 void\cf0  \cf5 Assign\cf0 ::parseAssign()\
\{\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  \cf8 //id=ID->parseIDForSS();\cf0 \
\
  \cf4 if\cf0 (curToken != \cf6 14\cf0 ) \{ cout<<\cf3 "Error-expecting = "\cf0 <<endl; exit(\cf6 1\cf0 ); \}\
  \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  exp.\cf7 parseExpression\cf0 (); \
\
  \cf4 if\cf0 (curToken != \cf6 12\cf0 ) \{ cout<<\cf3 "Error-expecting ; "\cf0 <<endl; exit(\cf6 1\cf0 ); \}\
  \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  \cf8 //id=ID->parseIDForSS();\cf0 \
\}\
\
\cf4 void\cf0  \cf5 Assign\cf0 ::printAssign()\
\{\
  \cf8 //cout<<id.getName();\cf0 \
  exp.\cf7 printExpression\cf0 ();\
  cout<<\cf3 " ; "\cf0 ;\
\}\
\
\cf4 void\cf0  \cf5 Assign\cf0 ::execAssign()\
\{\
  \cf5 resultAssign\cf0 =exp.\cf7 execExpression\cf0 ();\
  id.\cf7 setIDVal\cf0 (\cf5 resultAssign\cf0 );\
\}\
}