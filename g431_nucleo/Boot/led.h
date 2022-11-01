/************************************************************************************//**
* \file         Demo/ARMCM4_STM32G4_Nucleo_G474RE_GCC/Boot/App/led.h
* \brief        LED driver header file.
* \ingroup      Boot_ARMCM4_STM32G4_Nucleo_G474RE_GCC
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2021  by Feaser    http://www.feaser.com    All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of OpenBLT. OpenBLT is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option) any later
* version.
*
* OpenBLT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
*
* You have received a copy of the GNU General Public License along with OpenBLT. It 
* should be located in ".\Doc\license.html". If not, contact Feaser to obtain a copy.
*
* \endinternal
****************************************************************************************/
#ifndef LED_H
#define LED_H

#define LED_PORT    GPIOB
#define LED_PIN     LL_GPIO_PIN_8

/****************************************************************************************
* Function prototypes
****************************************************************************************/
void LedBlinkInit(blt_int16u interval_ms);
void LedBlinkTask(void);
void LedBlinkExit(void);


#endif /* LED_H */
/*********************************** end of led.h **************************************/
