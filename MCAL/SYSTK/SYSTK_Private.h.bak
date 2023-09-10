/*
 * SYSTK_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: khale
 */

#ifndef REPO_MCAL_SYSTK_SYSTK_PRIVATE_H_
#define REPO_MCAL_SYSTK_SYSTK_PRIVATE_H_
#include "../../LIB/STD_TYPES.h"

typedef struct
{
	volatile u32 SYS_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;

}SYSTK_t;


#define SYSTK_BASE_ADDRESS  0xE000E010

#define SYSTK  ((SYSTK_t*)(SYSTK_BASE_ADDRESS))

/************************************************************************/
/** Bits in STK_CTRL register */
#define STK_CTRL_ENABLE     0
#define STK_CTRL_TICKINT     1
#define STK_CTRL_CLKSOURCE   2
#define STK_CTRL_COUNTFLAG   16

/** Clock sources in STK_CTRL */
#define STK_AHB_DIV8         0
#define STK_AHB              1

/** Configuration values for status functions (STK_voidIntStatus) */
#define ENABLE               1
#define DISABLE              0

/** Clock source options */
#define RCC_HSI              0
#define RCC_HSE              1
#define RCC_PLL              2

/** Conversion factors for delays */
#define DELAY_FOR_MS         16000  /**< systemTick = 1/f, delay in milliseconds */
#define DELAY_FOR_US         16     /**< systemTick = 1/f, delay in microseconds */

#endif /* REPO_MCAL_SYSTK_SYSTK_PRIVATE_H_ */
