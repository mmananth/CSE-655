{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _STATEMENTSEQ_H\
#define _STATEMENTSEQ_H\
#include \cf3 "Stmt.h"\cf2 \
\cf0 \
\cf4 class\cf0  Stmt;\
\cf4 class\cf0  StmtSeq:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 public\cf0 :\
  StmtSeq()\{\};\
  \cf5 Stmt\cf0  *\cf5 stmt\cf0 ;\
  \cf4 void\cf0  parseSS();\
  \cf4 void\cf0  printSS();\
  \cf4 void\cf0  execSS();\
\};\
\
\cf2 #endif \
}