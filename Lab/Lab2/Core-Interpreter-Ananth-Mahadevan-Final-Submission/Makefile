CC=g++
//CFLAGS=-c -g -D ENABLE_DEBUG_PARSE
CFLAGS=-c -g 
LDFLAGS=
SOURCES=TestInterpreter.cpp \
	Tokenizer.cpp \
        Program.cpp \
        Decl.cpp \
        DeclSeq.cpp \
        Stmt.cpp \
        StmtSeq.cpp \
	idList.cpp \
	ID.cpp \
	Assign.cpp \
	IF.cpp \
	Loop.cpp \
	IN.cpp \
	OUT.cpp \
	Operator.cpp \
	Trm.cpp \
	Expression.cpp \
	Condition.cpp \
	Compare.cpp \
	CompareOperator.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TestInterpreter

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
#	$(CC) $(CFLAGS) $< -o $@
TestInterpreter.o: TestInterpreter.cpp
	$(CC) $(CFLAGS) $^ -o $@
Tokenizer.o: Tokenizer.cpp
	$(CC) $(CFLAGS) $^ -o $@
Program.o: Program.cpp
	$(CC) $(CFLAGS) $^ -o $@
Decl.o: Decl.cpp
	$(CC) $(CFLAGS) $^ -o $@
DeclSeq.o: DeclSeq.cpp
	$(CC) $(CFLAGS) $^ -o $@
Stmt.o: Stmt.cpp
	$(CC) $(CFLAGS) $^ -o $@
StmtSeq.o: StmtSeq.cpp
	$(CC) $(CFLAGS) $^ -o $@
idList.o: idList.cpp
	$(CC) $(CFLAGS) $^ -o $@
ID.o: ID.cpp
	$(CC) $(CFLAGS) $^ -o $@
Assign.o: Assign.cpp
	$(CC) $(CFLAGS) $^ -o $@
IF.o: IF.cpp
	$(CC) $(CFLAGS) $^ -o $@
Loop.o: Loop.cpp
	$(CC) $(CFLAGS) $^ -o $@
IN.o: IN.cpp
	$(CC) $(CFLAGS) $^ -o $@
OUT.o: OUT.cpp
	$(CC) $(CFLAGS) $^ -o $@
Operator.o: Operator.cpp
	$(CC) $(CFLAGS) $^ -o $@
Trm.o: Trm.cpp
	$(CC) $(CFLAGS) $^ -o $@
Expression.o: Expression.cpp
	$(CC) $(CFLAGS) $^ -o $@
Condition.o: Condition.cpp
	$(CC) $(CFLAGS) $^ -o $@
Compare.o: Compare.cpp
	$(CC) $(CFLAGS) $^ -o $@
CompareOperator.o: CompareOperator.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f $(EXECUTABLE) $(OBJECTS)
