################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ADC.c" \
"../Sources/Exceptions.c" \
"../Sources/HCI.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/blue tooth.c" \
"../Sources/control.c" \
"../Sources/counter.c" \
"../Sources/disableWatchdog.c" \
"../Sources/distance.c" \
"../Sources/initAdc.c" \
"../Sources/initModesAndClock.c" \
"../Sources/initOLED.c" \
"../Sources/initPWM.c" \
"../Sources/initPress.c" \
"../Sources/initsteer.c" \
"../Sources/interrupt.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \
"../Sources/oled.c" \
"../Sources/steer.c" \

C_SRCS += \
../Sources/ADC.c \
../Sources/Exceptions.c \
../Sources/HCI.c \
../Sources/IntcInterrupts.c \
../Sources/blue\ tooth.c \
../Sources/control.c \
../Sources/counter.c \
../Sources/disableWatchdog.c \
../Sources/distance.c \
../Sources/initAdc.c \
../Sources/initModesAndClock.c \
../Sources/initOLED.c \
../Sources/initPWM.c \
../Sources/initPress.c \
../Sources/initsteer.c \
../Sources/interrupt.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \
../Sources/oled.c \
../Sources/steer.c \

OBJS += \
./Sources/ADC_c.obj \
./Sources/Exceptions_c.obj \
./Sources/HCI_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/blue\ tooth_c.obj \
./Sources/control_c.obj \
./Sources/counter_c.obj \
./Sources/disableWatchdog_c.obj \
./Sources/distance_c.obj \
./Sources/initAdc_c.obj \
./Sources/initModesAndClock_c.obj \
./Sources/initOLED_c.obj \
./Sources/initPWM_c.obj \
./Sources/initPress_c.obj \
./Sources/initsteer_c.obj \
./Sources/interrupt_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/oled_c.obj \
./Sources/steer_c.obj \

OBJS_QUOTED += \
"./Sources/ADC_c.obj" \
"./Sources/Exceptions_c.obj" \
"./Sources/HCI_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/blue tooth_c.obj" \
"./Sources/control_c.obj" \
"./Sources/counter_c.obj" \
"./Sources/disableWatchdog_c.obj" \
"./Sources/distance_c.obj" \
"./Sources/initAdc_c.obj" \
"./Sources/initModesAndClock_c.obj" \
"./Sources/initOLED_c.obj" \
"./Sources/initPWM_c.obj" \
"./Sources/initPress_c.obj" \
"./Sources/initsteer_c.obj" \
"./Sources/interrupt_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \
"./Sources/oled_c.obj" \
"./Sources/steer_c.obj" \

C_DEPS += \
./Sources/ADC_c.d \
./Sources/Exceptions_c.d \
./Sources/HCI_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/blue\ tooth_c.d \
./Sources/control_c.d \
./Sources/counter_c.d \
./Sources/disableWatchdog_c.d \
./Sources/distance_c.d \
./Sources/initAdc_c.d \
./Sources/initModesAndClock_c.d \
./Sources/initOLED_c.d \
./Sources/initPWM_c.d \
./Sources/initPress_c.d \
./Sources/initsteer_c.d \
./Sources/interrupt_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \
./Sources/oled_c.d \
./Sources/steer_c.d \

OBJS_OS_FORMAT += \
./Sources/ADC_c.obj \
./Sources/Exceptions_c.obj \
./Sources/HCI_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/blue\ tooth_c.obj \
./Sources/control_c.obj \
./Sources/counter_c.obj \
./Sources/disableWatchdog_c.obj \
./Sources/distance_c.obj \
./Sources/initAdc_c.obj \
./Sources/initModesAndClock_c.obj \
./Sources/initOLED_c.obj \
./Sources/initPWM_c.obj \
./Sources/initPress_c.obj \
./Sources/initsteer_c.obj \
./Sources/interrupt_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/oled_c.obj \
./Sources/steer_c.obj \

C_DEPS_QUOTED += \
"./Sources/ADC_c.d" \
"./Sources/Exceptions_c.d" \
"./Sources/HCI_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/blue tooth_c.d" \
"./Sources/control_c.d" \
"./Sources/counter_c.d" \
"./Sources/disableWatchdog_c.d" \
"./Sources/distance_c.d" \
"./Sources/initAdc_c.d" \
"./Sources/initModesAndClock_c.d" \
"./Sources/initOLED_c.d" \
"./Sources/initPWM_c.d" \
"./Sources/initPress_c.d" \
"./Sources/initsteer_c.d" \
"./Sources/interrupt_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \
"./Sources/oled_c.d" \
"./Sources/steer_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/ADC_c.obj: ../Sources/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ADC.args" -o "Sources/ADC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/HCI_c.obj: ../Sources/HCI.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/HCI.args" -o "Sources/HCI_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/blue\ tooth_c.obj: ../Sources/blue\ tooth.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/blue tooth.args" -o "Sources/blue tooth_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/blue\ tooth_c.d: ../Sources/blue\ tooth.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/control_c.obj: ../Sources/control.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/control.args" -o "Sources/control_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/counter_c.obj: ../Sources/counter.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/counter.args" -o "Sources/counter_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/disableWatchdog_c.obj: ../Sources/disableWatchdog.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/disableWatchdog.args" -o "Sources/disableWatchdog_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/distance_c.obj: ../Sources/distance.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/distance.args" -o "Sources/distance_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initAdc_c.obj: ../Sources/initAdc.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/initAdc.args" -o "Sources/initAdc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initModesAndClock_c.obj: ../Sources/initModesAndClock.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/initModesAndClock.args" -o "Sources/initModesAndClock_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initOLED_c.obj: ../Sources/initOLED.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/initOLED.args" -o "Sources/initOLED_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initPWM_c.obj: ../Sources/initPWM.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/initPWM.args" -o "Sources/initPWM_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initPress_c.obj: ../Sources/initPress.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/initPress.args" -o "Sources/initPress_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initsteer_c.obj: ../Sources/initsteer.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/initsteer.args" -o "Sources/initsteer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/interrupt_c.obj: ../Sources/interrupt.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/interrupt.args" -o "Sources/interrupt_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/oled_c.obj: ../Sources/oled.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/oled.args" -o "Sources/oled_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/steer_c.obj: ../Sources/steer.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/steer.args" -o "Sources/steer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


