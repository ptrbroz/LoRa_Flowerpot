################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/run/media/Zaja/DA50F9F050F9D36D/Users/Lenovo/OneDrive\ -\ České\ vysoké\ učení\ technické\ v\ Praze/Skola/FEL\ -\ CVUT/Druhý\ semestr/SPD/Projekt/STM32CubeExpansion_LRWAN_V2.1.0/Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.c 

OBJS += \
./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.o 

C_DEPS += \
./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.o: /run/media/Zaja/DA50F9F050F9D36D/Users/Lenovo/OneDrive\ -\ České\ vysoké\ učení\ technické\ v\ Praze/Skola/FEL\ -\ CVUT/Druhý\ semestr/SPD/Projekt/STM32CubeExpansion_LRWAN_V2.1.0/Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.c Drivers/BSP/B-L072Z-LRWAN1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DCMWX1ZZABZ0XX -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-B-2d-L072Z-2d-LRWAN1

clean-Drivers-2f-BSP-2f-B-2d-L072Z-2d-LRWAN1:
	-$(RM) ./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.d ./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.o

.PHONY: clean-Drivers-2f-BSP-2f-B-2d-L072Z-2d-LRWAN1

