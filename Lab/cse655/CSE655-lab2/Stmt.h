{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _STATEMENT_H_\
#define _STATEMENT_H_\
#include \cf3 "OUT.h"\cf2 \
#include \cf3 "IN.h"\cf2 \
#include \cf3 "IF.h"\cf2 \
#include \cf3 "Assign.h"\cf2 \
#include \cf3 "Loop.h"\cf2 \
\cf0 \
\cf4 class\cf0  IF;\
\cf4 class\cf0  Loop;\
\cf4 class\cf0  Stmt:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf4 private\cf0 :\
  \cf4 int\cf0  \cf5 altNum\cf0 ;\
\cf4 public\cf0 :\
  Stmt()\{\};\
  \cf4 int\cf0  \cf5 curToken\cf0 ;\
  \cf5 OUT\cf0  \cf4 out\cf0 ;\
  \cf5 IN\cf0  \cf4 in\cf0 ;\
  \cf5 IF\cf0  *\cf5 pif\cf0 ;\
  \cf5 Assign\cf0  \cf5 assign\cf0 ;\
  \cf5 Loop\cf0  *\cf5 loop\cf0 ;\
  \cf4 void\cf0  parseStmt();\
  \cf4 void\cf0  printStmt();\
  \cf4 void\cf0  execStmt();\
\};\
\
\cf2 #endif \
}