{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Trm.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf4 void\cf0  \cf5 Trm\cf0 ::parseTrm()\
\{\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  oper->\cf6 parseOperator\cf0 ();\
  \cf4 if\cf0 (curToken == \cf7 24\cf0 )\
  \{\
    \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
    \cf6 parseTrm\cf0 ();\
  \}\
\}\
\
\cf4 void\cf0  \cf5 Trm\cf0 ::printTrm()\
\{\
  oper->\cf6 printOperator\cf0 ();\
  cout<<\cf3 "*"\cf0 ;\
  \cf6 printTrm\cf0 ();\
\}\
\
\cf4 int\cf0  \cf5 Trm\cf0 ::execTrm()\
\{\
  resultTrm=(oper->\cf6 execOperator\cf0 () * \cf6 execTrm\cf0 ());\
  \cf4 return\cf0  resultTrm;\
\}\
}