################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Adventures.cpp \
../src/Game.cpp \
../src/MainShip.cpp \
../src/TextureManager.cpp 

OBJS += \
./src/Adventures.o \
./src/Game.o \
./src/MainShip.o \
./src/TextureManager.o 

CPP_DEPS += \
./src/Adventures.d \
./src/Game.d \
./src/MainShip.d \
./src/TextureManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


