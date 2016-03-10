################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ConstTest.cpp \
../DogFactory.cpp \
../ExceptTest.cpp \
../NotAllowed.cpp \
../RAII.cpp \
../Singleton.cpp \
../Timer.cpp \
../VirtualTest.cpp 

OBJS += \
./ConstTest.o \
./DogFactory.o \
./ExceptTest.o \
./NotAllowed.o \
./RAII.o \
./Singleton.o \
./Timer.o \
./VirtualTest.o 

CPP_DEPS += \
./ConstTest.d \
./DogFactory.d \
./ExceptTest.d \
./NotAllowed.d \
./RAII.d \
./Singleton.d \
./Timer.d \
./VirtualTest.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"D:\cygwin64\usr\include" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


