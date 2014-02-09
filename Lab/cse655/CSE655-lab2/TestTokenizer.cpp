{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf360
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red63\green110\blue116;
\red170\green13\blue145;\red38\green71\blue75;\red28\green0\blue207;\red0\green116\blue0;}
\margl1440\margr1440\vieww25100\viewh15040\viewkind0
\deftab480
\pard\tx480\pardeftab480\ql\qnatural\pardirnatural

\f0\fs20 \cf2 \CocoaLigature0 #include \cf3 "Tokenizer.h"\cf2 \
#include \cf3 "Program.h"\cf2 \
\cf0 \
\cf4 Tokenizer\cf0  \cf4 t\cf0 ;\
\cf5 int\cf0  main(\cf5 int\cf0  argc, \cf5 char\cf0 * argv[])\
\{\
    \cf4 Program\cf0  p;\
    \cf4 t\cf0 .\cf6 setIndex\cf0 (-\cf7 1\cf0 );\
    \cf4 t\cf0 .\cf6 getInput\cf0 (argv[\cf7 1\cf0 ]);\
    \cf4 t\cf0 .\cf6 skipToken\cf0 ();\
    \cf5 int\cf0  tok=\cf4 t\cf0 .\cf6 getToken\cf0 ();\
    cout<<\cf3 "------------------------------------------------"\cf0 <<endl;\
    cout<<\cf3 "The tokens for the given input "\cf0 <<argv[\cf7 1\cf0 ]<<\cf3 " are:"\cf0 <<endl;\
    cout<<\cf3 "------------------------------------------------"\cf0 <<endl;\
    \cf5 while\cf0 (tok != \cf7 33\cf0 )\
    \{\
        tok=\cf4 t\cf0 .\cf6 getToken\cf0 ();\
        \cf4 t\cf0 .\cf6 skipToken\cf0 ();\
        \cf5 if\cf0 (tok == -\cf7 1\cf0 )\
            cout<<\cf3 "error in input"\cf0 <<endl;\
        \cf5 else\cf0  \cf5 if\cf0 (tok == -\cf7 2\cf0 )\
        \{\
            cout<<\cf3 "error at the end of the inputfile"\cf0 <<endl;\
            cout<<\cf7 33\cf0 <<endl;\
            \cf5 break\cf0 ;\
        \}\
        \cf5 else\cf0 \{ \
            cout<<tok<<endl;\
        \}\
    \}\
    \cf8 //string name=t.idName(1);\cf0 \
    \cf8 //cout<<"name is"<<name<<endl;\cf0 \
    cout<<\cf3 "------------------------------------------------"\cf0 <<endl;\
    p.\cf6 parseProgram\cf0 ();\
    \
    \cf8 /*cout<<"------------------------------------------------"<<endl;\
     cout<<"The pretty print version of the input file is:"<<endl;\
     cout<<"------------------------------------------------"<<endl;\
     p.printProgram();\
     \
     cout<<"------------------------------------------------"<<endl;\
     cout<<"Beginning execution..."<<endl;\
     p.parseInputFile2(argv[2]);\
     p.execProgram();*/\cf0 \
\}\
}