{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _TRM_H_\
#define _TRM_H_\
#include \cf3 "ConflictRes.h"\cf2 \
\cf0 \
\cf4 class\cf0  Operator1;\
\cf4 class\cf0  Trm:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 public\cf0 :\
  Trm()\{\};\
  \cf5 Operator1\cf0  *\cf5 oper\cf0 ;\
  \cf4 int\cf0  \cf5 curToken\cf0 , \cf5 resultTrm\cf0 ;\
  \cf4 void\cf0  parseTrm();\
  \cf4 void\cf0  printTrm();\
  \cf4 int\cf0  execTrm();\
\};\
\
\cf2 #endif \
}