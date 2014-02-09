################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Assign.o \
../Compare.o \
../CompareOperator.o \
../Condition.o \
../Decl.o \
../DeclSeq.o \
../Expression.o \
../ID.o \
../IF.o \
../IN.o \
../Letter.o \
../Loop.o \
../Number.o \
../OUT.o \
../OUT1.o \
../Operator.o \
../Program.o \
../Stmt.o \
../StmtSeq.o \
../TestTokenizer.o \
../Tokenizer.o \
../Trm.o \
../built-in.o \
../core.o \
../idList.o 

CPP_SRCS += \
../Assign.cpp \
../Compare.cpp \
../CompareOperator.cpp \
../Comparison.cpp \
../Condition.cpp \
../Decl.cpp \
../DeclSeq.cpp \
../Digit.cpp \
../Expression.cpp \
../ID.cpp \
../IF.cpp \
../IN.cpp \
../Letter.cpp \
../Loop.cpp \
../Number.cpp \
../OUT.cpp \
../Operator.cpp \
../Program.cpp \
../Stmt.cpp \
../StmtSeq.cpp \
../TestMMA.cpp \
../TestTokenizer.cpp \
../Tokenizer.cpp \
../Trm.cpp \
../idList.cpp \
../test.cpp 

OBJS += \
./Assign.o \
./Compare.o \
./CompareOperator.o \
./Comparison.o \
./Condition.o \
./Decl.o \
./DeclSeq.o \
./Digit.o \
./Expression.o \
./ID.o \
./IF.o \
./IN.o \
./Letter.o \
./Loop.o \
./Number.o \
./OUT.o \
./Operator.o \
./Program.o \
./Stmt.o \
./StmtSeq.o \
./TestMMA.o \
./TestTokenizer.o \
./Tokenizer.o \
./Trm.o \
./idList.o \
./test.o 

CPP_DEPS += \
./Assign.d \
./Compare.d \
./CompareOperator.d \
./Comparison.d \
./Condition.d \
./Decl.d \
./DeclSeq.d \
./Digit.d \
./Expression.d \
./ID.d \
./IF.d \
./IN.d \
./Letter.d \
./Loop.d \
./Number.d \
./OUT.d \
./Operator.d \
./Program.d \
./Stmt.d \
./StmtSeq.d \
./TestMMA.d \
./TestTokenizer.d \
./Tokenizer.d \
./Trm.d \
./idList.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


