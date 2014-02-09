{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _IF_H_\
#define _IF_H_\
#include \cf3 "Tokenizer.h"\cf2 \
#include \cf3 "Condition.h"\cf2 \
#include \cf3 "StmtSeq.h"\cf2 \
\cf0 \
\cf4 class\cf0  Condition;\
\cf4 class\cf0  StmtSeq;\
\cf4 class\cf0  IF:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 public\cf0 :\
  IF()\{\};\
  ~IF();\
  \cf5 Condition\cf0  *\cf5 cond\cf0 ;\
  \cf5 StmtSeq\cf0  *\cf5 ss\cf0 ;\
  \cf4 int\cf0  \cf5 curToken\cf0 ;\
  \cf4 bool\cf0  \cf5 valueIfBool\cf0 ;\
  \cf4 void\cf0  parseIF();\
  \cf4 void\cf0  printIF();\
  \cf4 void\cf0  execIF();\
\};\
\
\cf2 #endif \
}