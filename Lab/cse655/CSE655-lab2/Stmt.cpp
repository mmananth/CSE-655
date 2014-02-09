{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red63\green110\blue116;\red0\green116\blue0;\red38\green71\blue75;\red28\green0\blue207;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Stmt.h"\cf2 \
\cf0 \
\cf4 extern\cf0  \cf5 Tokenizer\cf0  \cf5 t\cf0 ;\
\cf6 //IF pif;\cf0 \
\
\cf4 void\cf0  \cf5 Stmt\cf0 ::parseStmt()\
\{\
  curToken=\cf5 t\cf0 .\cf7 getToken\cf0 ();     \
 \
  \cf4 if\cf0 (curToken == \cf8 32\cf0 )\
  \{\
    altNum=\cf8 1\cf0 ;\
    assign.\cf7 parseAssign\cf0 ();\
  \}\
\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf8 5\cf0 )\
  \{\
    altNum=\cf8 2\cf0 ;\
    pif->\cf7 parseIF\cf0 ();\
    \cf6 //if(pif.checkIf == pif.checkIfEnd) \{ cout<<"If and End match "<<endl; \}\cf0 \
    \cf6 //else \{ cout<<"No matching end for If. Exiting... "<<endl; \}\cf0 \
  \}\
\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf8 8\cf0 )\
  \{\
    altNum=\cf8 3\cf0 ;\
    loop->\cf7 parseLoop\cf0 ();\
    \cf6 //if(loop.checkWhile == loop.checkWhileEnd) \{ cout<<"While and End match "<<endl; \}\cf0 \
    \cf6 //else \{ cout<<"No matching end for While. Exiting... "<<endl; \}\cf0 \
  \}\
\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf8 10\cf0 )\
  \{\
    altNum=\cf8 4\cf0 ;\
    in.\cf7 parseIN\cf0 ();\
  \}\
\
  \cf4 else\cf0  \cf4 if\cf0 (curToken == \cf8 11\cf0 )\
  \{\
    altNum=\cf8 5\cf0 ;\
    out.\cf7 parseOUT\cf0 ();\
  \}\
  \cf4 else\cf0  \
    cout<<\cf3 "Error in Stmt.cpp. Exiting..."\cf0 <<endl;\
\}\
\
\cf4 void\cf0  \cf5 Stmt\cf0 ::printStmt()\
\{\
  \cf4 if\cf0 (altNum==\cf8 1\cf0 ) \{\
    assign.\cf7 printAssign\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 2\cf0 ) \{\
    pif->\cf7 printIF\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 3\cf0 ) \{\
    loop->\cf7 printLoop\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 4\cf0 ) \{\
    in.\cf7 printIN\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 5\cf0 ) \{\
    out.\cf7 printOUT\cf0 ();\
  \}\
\}\
\
\cf4 void\cf0  \cf5 Stmt\cf0 ::execStmt()\
\{\
  \cf4 if\cf0 (altNum==\cf8 1\cf0 ) \{\
    assign.\cf7 execAssign\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 2\cf0 ) \{\
    pif->\cf7 execIF\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 3\cf0 ) \{\
    loop->\cf7 execLoop\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 4\cf0 ) \{\
    in.\cf7 execIN\cf0 ();\
  \}\
  \cf4 if\cf0 (altNum==\cf8 5\cf0 ) \{\
    out.\cf7 execOUT\cf0 ();\
  \}\
\}\
}