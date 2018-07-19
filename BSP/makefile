################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPCP_DEPS)),)
-include $(CPCP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

#rebuild target
rebuild: clean all

# All Target
all: LeoMini_LED.elf

# Tool invocations
LeoMini_LED.elf: $(OBJS) $(USER_OBJS) $(ASM)
	@echo 'Building target: $@'
	@echo 'Invoking: PowerPC C Linker'
	"$(POWERPC_TOOLS)/bin/ppc-vle-gcc" -o  "LeoMini_LED.elf" -nocrt0 -T"D:\Projects\Leopard\LeoMini_LED\ld\SPC56EL70.ld" "src\crt0.o" "src\flexcan.o" "src\intc.o" "src\main.o" "src\me.o" "src\pit.o" -Wl,--gc-sections -mcpu=z420n3 -L../ld -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -msoft-float -mvle -Wl,--extmap=a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS)$(CPCP_DEPS) LeoMini_LED.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
