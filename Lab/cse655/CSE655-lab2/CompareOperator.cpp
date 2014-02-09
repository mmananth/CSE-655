{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "CompareOperator.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf4 void\cf0  \cf5 CompareOperator\cf0 ::parseCompareOperator()\
\{\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken == \cf7 25\cf0 ) \{ altNum=\cf7 1\cf0 ; \}\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf7 26\cf0 ) \{ altNum=\cf7 2\cf0 ; \}\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf7 27\cf0 ) \{ altNum=\cf7 3\cf0 ; \}\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf7 28\cf0 ) \{ altNum=\cf7 4\cf0 ; \}\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf7 29\cf0 ) \{ altNum=\cf7 5\cf0 ; \}\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf7 30\cf0 ) \{ altNum=\cf7 6\cf0 ; \}\
  \cf4 else\cf0  \{ cout<<\cf3 "Error-Unexpected Comparison Operators"\cf0 <<endl; \}\
  \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 CompareOperator\cf0 ::printCompareOperator()\
\{\
\}\
\
\cf4 void\cf0  \cf5 CompareOperator\cf0 ::execCompareOperator()\
\{\
\}\
}