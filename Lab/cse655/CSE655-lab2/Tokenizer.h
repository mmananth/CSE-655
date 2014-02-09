{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red28\green0\blue207;\red0\green116\blue0;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _TOKENIZER_H\
#define _TOKENIZER_H\
#include\cf3 <fstream>\cf2 \
#include\cf3 <iostream>\cf2 \
#include\cf3 <string>\cf2 \
#include\cf3 <map>\cf2 \
#include\cf3 <locale>\cf2 \
#include\cf3 <string.h>\cf2 \
#include\cf3 <stdlib.h>\cf2 \
\cf0 \
\cf4 using\cf0  \cf4 namespace\cf0  \cf5 std\cf0 ;\
\
\cf4 class\cf0  Tokenizer\
\{\
\cf4 private\cf0 :\
  locale \cf5 loc\cf0 ;\
  string \cf5 lines\cf0 [\cf6 1000\cf0 ],\cf5 line\cf0 ,\cf5 lines1\cf0 [\cf6 1000\cf0 ],\cf5 line1\cf0 ,\cf5 lineCnt\cf0 ,\cf5 substring1\cf0 ;\
  \cf4 char\cf0  *\cf5 ch\cf0 , *\cf5 chra\cf0 , *\cf5 cha\cf0 , *\cf5 cstr\cf0 , *\cf5 cstra\cf0 , *\cf5 pt\cf0 , *\cf5 pt1\cf0 , *\cf5 pta\cf0 , \cf5 c\cf0 , *\cf5 cstr1\cf0 ;\
\
  size_t \cf5 found\cf0 ;\
  \cf4 int\cf0  \cf5 k\cf0 ,\cf5 n\cf0 ,\cf5 m\cf0 ,\cf5 count\cf0 ;\
  \cf7 //static int count;\cf0 \
  \cf4 int\cf0  \cf5 flag_Plus\cf0 , \cf5 flag_Equal\cf0 , \cf5 flag_LeftParentheses\cf0 , \cf5 flag_Semicolon\cf0 , \cf5 flag_Num\cf0 , \cf5 flag_Upper\cf0 , \cf5 flag_Alnum\cf0 , \cf5 flag_RightParentheses\cf0 , \cf5 flag_Comma\cf0 , \cf5 flag_Variable\cf0 , \cf5 flag_LeftSquare\cf0 , \cf5 flag_RightSquare\cf0 , \cf5 good\cf0 , \cf5 index\cf0 ;\
  \cf7 //int tokenDone;\cf0 \
  \cf7 //static int tokenDone;\cf0 \
\
  ifstream \cf5 istr\cf0 , \cf5 istr2\cf0 , \cf5 istr3\cf0 ;\
  ofstream \cf5 ostr\cf0 , \cf5 ostr2\cf0 ;\
\
\cf4 public\cf0 :\
  \cf4 int\cf0  intVal();\
  \cf7 /*void idName();\
  void processFile();*/\cf0 \
  Tokenizer();\
  \cf4 void\cf0  getInput(\cf4 char\cf0 * arg);\
  \cf4 int\cf0  getToken();\
  \cf4 void\cf0  parseToken();\
  \cf4 void\cf0  skipToken();\
  \cf4 void\cf0  setIndex(\cf4 int\cf0 );\
  \cf4 void\cf0  printLines();\
  string getIdName();\
  \cf7 //int getNext();\cf0 \
\};\
\cf2 #endif\
}