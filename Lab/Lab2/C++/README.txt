/*----------------------------------------------------------------------*/
/*README.txt -- Contains description of the files used in the program.	    */
/*Runfile.txt - Contains instructions for compiling and running the program.*/
/*Core-Interpreter-Document.txt -- Contains description of the overall design, testing methodology and known bugs 					     */
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* Description of the files used for Parsing, Printing and Execution of */
/* the Core program							*/
/*----------------------------------------------------------------------*/
1) TestTokenizer.cpp
  -- Contains the Main method. This file drives the entire program by tokenizing the input. It also calls the Parser, Printer and the Executor programs.

2) Tokenizer.cpp
  -- Contains methods to tokenize the Reserved words, Special Symbols, Integers and Identifiers.
 
3) Program.cpp
  -- Contains a method that tokenizes the second inputfile entered via the command line. The parseProgram, printProgram and execProgram methods recursively call the appropriate parser, printer and the executor sections of the Core interpreter.

4) DeclSeq.cpp
  -- Contains functions that perform operations on the Declaration Sequence of the Core program.

5) Decl.cpp
  -- Checks if the first key word is an "int" and calls the idList.cpp file to process the declared variables.

6) StmtSeq.cpp
  -- Contains functions that perform operations on the Statement Sequence of the Core program.

7) Stmt.cpp
  -- The functions in this file, assign an alternate number based on the token given to it. The alternate numbers are:
Assign - 1
if     - 2
loop   - 3
in     - 4
out    - 5

8) idList.cpp
  -- Used for processing a list of identifiers (IDs). The IDs can either be just one or can be seperated by commas.
 
9) ID.cpp
  -- Contains static methods to allocate objects for IDs only in the case where it has not been already allocated.

10) Assign.cpp
  -- Contains functions for processing the allocation statements. 

11) IF.cpp
  -- This is for processing the IF loop statements. IF has to be terminated by an "end". The IF loop can either have a THEN, ELSE and an END following it or just a THEN and an END.

12) Loop.cpp
  -- This file has functions for processing the WHILE loop statements. A WHILE has to be terminated by an "end". A WHILE statement is followed by a Condition, followed by a LOOP keyword. The LOOP keyword is followed by the Statement_Sequence and an END keyword.

13) OUT.cpp
  -- The parser function in this file checks for the key word "write". Based on the count of the input values, it displays the variable and its corresponding value on the screen.

14) IN.cpp
  -- The parser function checks for the key word "read". The values that were tokenized from the second command line input parameter are stored in the corresponding variables that come after "read".

15) Condition.cpp
  -- The condition statement can either follow an IF loop or a WHILE loop. The Condition is indicated by - "(", "!" or "[".

16) Compare.cpp
  -- The Compare file is used for comparing the values between 2 variables. The comparison operators are - "!=", "==", "<", ">", "<=", ">=".

17) Expression.cpp
  -- This is used for adding or subtracting 2 or more variables and also for multiplying the values of variables.

18) Trm.cpp
  -- This is for multiplying the values of 2 or more variables.

19) Operator.cpp
  -- This is for performing operations on a mathmatical expression.

20) CompareOperator.cpp
  -- As mentioned under "Compare.cpp", this has functions to check, print and perform operations using the comparison operators.

21) Makefile
  -- In order to compile and build all the different C++ files and their corresponding headers, the makefile is used.

Apart from the above, all *.cpp files have a corresponding header (*.h) file as well.

/*----------------------------------------------------------------------*/
/* Instructions to the Grader on compiling and executing the program	*/
/*----------------------------------------------------------------------*/
1) To Compile the program, run the below command at the command prompt:

> make
--------------
sample output
--------------
g++ -c -g  TestInterpreter.cpp -o TestInterpreter.o
g++ -c -g  Tokenizer.cpp -o Tokenizer.o
g++ -c -g  Program.cpp -o Program.o
g++ -c -g  Decl.cpp -o Decl.o
g++ -c -g  DeclSeq.cpp -o DeclSeq.o

2) To clean or remove the object files, run the below command:

> make clean
