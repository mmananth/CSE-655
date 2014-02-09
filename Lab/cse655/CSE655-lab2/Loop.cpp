{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Loop.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\cf6 //StmtSeq ss;\cf0 \
\
\cf4 void\cf0  \cf5 Loop\cf0 ::parseLoop()\
\{\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf8 8\cf0 )\
  \{\
    cout<<\cf3 "Error-expecting while"\cf0 <<endl;\
    exit(\cf8 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  cond->\cf7 parseCondition\cf0 ();\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf8 9\cf0 )\{\
    cout<<\cf3 "Error-expecting loop"\cf0 <<endl;\
    exit(\cf8 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  ss->\cf7 parseSS\cf0 ();\
\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf8 3\cf0 ) \{\
    cout<<\cf3 "Error-expecting end"\cf0 <<endl;\
    exit(\cf8 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf8 12\cf0 ) \{\
    cout<<\cf3 "Error-expecting ;"\cf0 <<endl;\
    exit(\cf8 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf7 skipToken\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 Loop\cf0 ::printLoop()\
\{\
  cout<<\cf3 "while "\cf0 ;\
  cond->\cf7 printCondition\cf0 ();\
  cout<<\cf3 " loop"\cf0 ;\
  ss->\cf7 printSS\cf0 ();\
  cout<<\cf3 " end"\cf0 ;\
\}\
\
\cf4 void\cf0  \cf5 Loop\cf0 ::execLoop()\
\{\
  checkCond=\cf4 true\cf0 ;\
  \cf4 while\cf0 (checkCond==\cf4 true\cf0 ) \{\
    checkCond=cond->\cf7 execCondition\cf0 ();\
    ss->\cf7 execSS\cf0 ();\
  \}\
\}\
}