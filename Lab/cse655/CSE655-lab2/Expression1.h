{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _EXPRESSION1_H_\
#define _EXPRESSION1_H_\
#include \cf3 "ConflictRes.h"\cf2 \
\cf0 \
\cf4 class\cf0  Trm;\
\cf4 class\cf0  Expression1:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 public\cf0 :\
  Expression1()\{\};\
  \cf5 Trm\cf0  *\cf5 trm\cf0 ;\
  \cf4 int\cf0  \cf5 curToken\cf0 ;\
  \cf4 int\cf0  \cf5 altNum\cf0 ;\
  \cf4 void\cf0  parseExpression();\
  \cf4 void\cf0  printExpression();\
  \cf4 int\cf0  execExpression();\
\};\
\
\cf2 #endif \
}