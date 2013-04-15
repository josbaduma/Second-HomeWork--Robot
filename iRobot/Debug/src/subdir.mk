################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ImageVideoDetection.cpp \
../src/Individual.cpp \
../src/ListQueue.cpp \
../src/ListStack.cpp \
../src/MainThreads.cpp \
../src/MatrixNode.cpp \
../src/PathFinding.cpp \
../src/SimpleList.cpp \
../src/SimpleNode.cpp \
../src/main.cpp 

OBJS += \
./src/ImageVideoDetection.o \
./src/Individual.o \
./src/ListQueue.o \
./src/ListStack.o \
./src/MainThreads.o \
./src/MatrixNode.o \
./src/PathFinding.o \
./src/SimpleList.o \
./src/SimpleNode.o \
./src/main.o 

CPP_DEPS += \
./src/ImageVideoDetection.d \
./src/Individual.d \
./src/ListQueue.d \
./src/ListStack.d \
./src/MainThreads.d \
./src/MatrixNode.d \
./src/PathFinding.d \
./src/SimpleList.d \
./src/SimpleNode.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


