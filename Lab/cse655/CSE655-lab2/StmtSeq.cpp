{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "StmtSeq.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\cf6 //Stmt stmt;\cf0 \
\
\cf4 void\cf0  \cf5 StmtSeq\cf0 ::parseSS()\
\{\
  \cf4 int\cf0  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  stmt->\cf7 parseStmt\cf0 ();\
  \cf4 if\cf0 ( (curToken == \cf8 32\cf0 ) || (curToken == \cf8 5\cf0 ) || (curToken == \cf8 8\cf0 ) || (curToken == \cf8 10\cf0 ) || (curToken == \cf8 11\cf0 ) )\
  \{\
    \cf7 parseSS\cf0 ();\
  \}\
\}\
\
\cf4 void\cf0  \cf5 StmtSeq\cf0 ::printSS()\
\{\
  stmt->\cf7 printStmt\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 StmtSeq\cf0 ::execSS()\
\{\
  stmt->\cf7 execStmt\cf0 ();\
\}\
}