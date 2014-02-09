{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red38\green71\blue75;\red28\green0\blue207;\red0\green116\blue0;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "idList.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\
\cf4 void\cf0  \cf5 idList\cf0 ::parseIDListForDS()\
\{\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken == \cf7 13\cf0 )\{\
    \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
    curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
    \cf4 if\cf0 (curToken == \cf7 32\cf0 )\{\
      id.\cf6 parseIDForDS\cf0 ();\
    \} \
    \cf4 else\cf0  \{\
      cout<<\cf3 "Error-Expecting an integer value. Exiting"\cf0 <<endl;\
      exit(\cf7 0\cf0 );\
    \}\
  \}\
\}\
\
\cf4 void\cf0  \cf5 idList\cf0 ::parseIDListForSS()\
\{\
  curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
  \cf4 if\cf0 (curToken == \cf7 13\cf0 )\{\
    \cf5 t\cf0 .\cf6 skipToken\cf0 ();\
    curToken=\cf5 t\cf0 .\cf6 getToken\cf0 ();\
    \cf4 if\cf0 (curToken == \cf7 32\cf0 )\{\
      id.\cf6 parseIDForDS\cf0 ();\
    \} \
    \cf4 else\cf0  \{\
      cout<<\cf3 "Error-Expecting an integer value. Exiting"\cf0 <<endl;\
      exit(\cf7 0\cf0 );\
    \}\
  \}\
\}\
\
\cf4 void\cf0  \cf5 idList\cf0 ::printIDList()\
\{\
  strID=id.\cf6 getIDName\cf0 ();\
  cout<<strID<<endl;\
  cout<<\cf3 ", "\cf0 ;\
  \cf6 printIDList\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 idList\cf0 ::readInput()\
\{\
  \cf8 //gnext=t.getNext();\cf0 \
  id.\cf6 setIDVal\cf0 (gnext);\
  \cf6 readInput\cf0 ();\
\}\
\
\cf4 void\cf0  \cf5 idList\cf0 ::writeOutput()\
\{\
  cout<<\cf3 " = "\cf0 ;\
  idValue=id.\cf6 getIDVal\cf0 ();\
  cout<<idValue;\
  \cf6 writeOutput\cf0 ();\
\}\
}