{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Compare.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf4 void\cf0  \cf5 Compare\cf0 ::parseCompare()\
\{\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf7 20\cf0 )\
  \{\
    cout<<\cf3 "error in parseCompare-Compare.h"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
  \}\
    \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
    op.\cf6 parseOperator\cf0 ();\
    compOp.\cf6 parseCompareOperator\cf0 ();\
    op.\cf6 parseOperator\cf0 ();\
    curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken != \cf7 21\cf0 )\
  \{\
    cout<<\cf3 "error in parseCompare-Compare.h"\cf0 <<endl;\
    exit(\cf7 0\cf0 );\
  \}\
    \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 Compare\cf0 ::printCompare()\
\{\
\}\
\
\cf4 void\cf0  \cf5 Compare\cf0 ::execCompare()\
\{\
\}\
}