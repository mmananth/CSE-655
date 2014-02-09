{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #ifndef _ID_H_\
#define _ID_H_\
#include \cf3 "Tokenizer.h"\cf2 \
#include \cf3 "ID.h"\cf2 \
#include \cf3 <string>\cf2 \
\cf0 \
\cf4 class\cf0  ID:\cf4 public\cf0  \cf5 Tokenizer\cf0 \
\{\
  string \cf5 name\cf0 ;\
  \cf4 int\cf0  \cf5 val\cf0 ;\
  \cf4 bool\cf0  \cf5 declared\cf0 ;\
  \cf4 bool\cf0  \cf5 initialized\cf0 ;\
  \cf6 //static ID* eIDs[20];\cf0 \
  \cf6 //static int idCount;\cf0 \
  ID(string \cf5 n\cf0 ) \{\
    \cf5 name\cf0 =\cf5 n\cf0 ;\
    \cf5 declared\cf0 =\cf4 false\cf0 ;\
    \cf5 initialized\cf0 =\cf4 false\cf0 ;\
  \};\
\cf4 public\cf0 :\
  ID()\{\};\
  \cf4 int\cf0  \cf5 curToken\cf0 ;\
  \cf6 //int getIDCal() \{ return val;\}\cf0 \
  \cf4 void\cf0  setIDVal(\cf4 int\cf0 );\
  \cf4 int\cf0  getIDVal();\
  string getIDName();\
  \cf4 static\cf0  \cf5 ID\cf0 * parseIDForDS();\
  \cf4 static\cf0  \cf5 ID\cf0 * parseIDForSS();\
  \cf4 void\cf0  insertSpace();\
  \cf4 void\cf0  getInitialized();\
\};\
\
\cf2 #endif \
}