{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _COREHEADER_H_\
#define _COREHEADER_H_\
#include \cf3 "DeclSeq.h"\cf2 \
#include \cf3 "StmtSeq.h"\cf2 \
#include \cf3 "ID.h"\cf2 \
\cf0 \
\cf4 class\cf0  Program:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
\cf6 //private:\cf0 \
  \cf6 //DeclSeq ds;\cf0 \
  \cf6 //StmtSeq ss;\cf0 \
\cf4 public\cf0 :\
  \cf5 DeclSeq\cf0  \cf5 ds\cf0 ;\
  \cf5 StmtSeq\cf0  \cf5 ss\cf0 ;\
  \cf5 ID\cf0  \cf4 id\cf0 ;\
  ifstream \cf5 ifstr\cf0 ;\
  string \cf5 linesFile2\cf0 [\cf7 100\cf0 ],\cf5 lineFile2\cf0 ;\
  \cf4 char\cf0 * \cf5 cstr2\cf0 , *\cf5 pt2\cf0 ;\
  \cf4 int\cf0  \cf5 curToken\cf0 ,\cf5 countFile2\cf0 ,\cf5 index2\cf0 ;\
  Program()\{ \cf5 index2\cf0 =\cf7 0\cf0 ; \} ;\
  \cf4 void\cf0  parseInputFile2(\cf4 char\cf0 * arg);\
  \cf4 int\cf0  getNextInputVal();\
  \cf4 void\cf0  parseProgram();\
  \cf4 void\cf0  printProgram();\
  \cf4 void\cf0  execProgram();\
\};\
\
\cf2 #endif \
}