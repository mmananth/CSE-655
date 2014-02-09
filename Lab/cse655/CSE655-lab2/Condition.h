{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _CONDITION_H_\
#define _CONDITION_H_\
#include \cf3 "Compare.h"\cf2 \
\cf0 \
\cf4 class\cf0  Condition:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 public\cf0 :\
  Condition()\{\};\
  \cf4 int\cf0  \cf5 curToken\cf0 ;\
  \cf4 int\cf0  \cf5 altNum\cf0 ;\
  \cf5 Compare\cf0  \cf5 comp\cf0 ;\
  \cf4 void\cf0  parseCondition();\
  \cf4 void\cf0  printCondition();\
  \cf4 bool\cf0  execCondition();\
\};\
\
\cf2 #endif \
}