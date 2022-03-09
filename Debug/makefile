################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS_Stack/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MDIO/subdir.mk
-include HAL/HLED/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NTI_MAR_RTOS_Project1.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_MAR_RTOS_Project1.elf secondary-outputs

# Tool invocations
NTI_MAR_RTOS_Project1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_MAR_RTOS_Project1.map -mmcu=atmega32 -o "NTI_MAR_RTOS_Project1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_MAR_RTOS_Project1.lss: NTI_MAR_RTOS_Project1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_MAR_RTOS_Project1.elf  >"NTI_MAR_RTOS_Project1.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_MAR_RTOS_Project1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_MAR_RTOS_Project1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_MAR_RTOS_Project1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
