################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/flexcan.c \
../src/intc.c \
../src/main.c \
../src/me.c \
../src/pit.c 

S_UPPER_SRCS += \
../src/crt0.S 

OBJS += \
./src/crt0.o \
./src/flexcan.o \
./src/intc.o \
./src/main.o \
./src/me.o \
./src/pit.o 

C_DEPS += \
./src/flexcan.d \
./src/intc.d \
./src/main.d \
./src/me.d \
./src/pit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: PowerPC Assembler'
	"$(POWERPC_TOOLS)/bin/ppc-vle-gcc" -c -I"D:\Projects\Leopard\LeoMini_LED\include" -Wa,--gdwarf-2 -mcpu=z420n3 -mregnames -msoft-float -mvle -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: PowerPC C Compiler'
	"$(POWERPC_TOOLS)/bin/ppc-vle-gcc" -c -I"D:\Projects\Leopard\LeoMini_LED\include" -fno-common -O0 -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -fshort-double -mcpu=z420n3 -mversion-info -mregnames -msoft-float -mvle -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


