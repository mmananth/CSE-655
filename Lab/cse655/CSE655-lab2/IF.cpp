{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "IF.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf5 IF\cf0 ::~IF()\
\{\
    \cf4 delete\cf0  cond;\
    \cf4 delete\cf0  ss;\
\}\
\
\cf4 void\cf0  \cf5 IF\cf0 ::parseIF()\
\{\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf7 5\cf0 )\
  \{\
    cout<<\cf3 "Error-expecting if"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
  cond->\cf6 parseCondition\cf0 ();\
\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf7 6\cf0 ) \{\
    cout<<\cf3 "Error-expecting then"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
  ss->\cf6 parseSS\cf0 ();\
\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken==\cf7 7\cf0 ) \{\
    \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
    ss->\cf6 parseSS\cf0 ();\
  \}\
\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken!=\cf7 3\cf0 )\{\
    cout<<\cf3 "Error-expecting end"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken!=\cf7 12\cf0 ) \{\
    cout<<\cf3 "Error-expecting ;"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
  \}\
  \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 IF\cf0 ::printIF()\
\{\
  cout<<\cf3 " If "\cf0 ;\
  cond->\cf6 printCondition\cf0 ();\
  cout<<\cf3 " then "\cf0 ;\
  ss->\cf6 printSS\cf0 ();\
  cout<<\cf3 " end "\cf0 ;\
\}\
\
\cf4 void\cf0  \cf5 IF\cf0 ::execIF()\
\{\
  valueIfBool=cond->\cf6 execCondition\cf0 ();\
  \cf4 if\cf0 (valueIfBool==\cf4 true\cf0 )\{\
    ss->\cf6 execSS\cf0 ();\
  \}\
\}\
}