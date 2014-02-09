{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _IDLIST_H_\
#define _IDLIST_H_\
#include \cf3 "ID.h"\cf2 \
\cf0 \
\cf4 class\cf0  idList:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 public\cf0 :\
  idList()\{\};\
  \cf5 ID\cf0  \cf4 id\cf0 ;\
  \cf4 int\cf0  \cf5 curToken\cf0 ;\
  \cf4 int\cf0  \cf5 idValue\cf0 ,\cf5 gnext\cf0 ;\
  string \cf5 strID\cf0 ;\
  \cf6 //ID(string) id;\cf0 \
  \cf4 void\cf0  parseIDListForDS();\
  \cf4 void\cf0  parseIDListForSS();\
  \cf4 void\cf0  printIDList();\
  \cf4 void\cf0  readInput();\
  \cf4 void\cf0  writeOutput();\
\};\
\
\cf2 #endif \
}