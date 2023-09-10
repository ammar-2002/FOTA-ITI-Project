/*
 * SYSTK_Config.h
 *
 *  Created on: Aug 15, 2023
 *      Author: khale
 */

#ifndef REPO_MCAL_SYSTK_SYSTK_CONFIG_H_
#define REPO_MCAL_SYSTK_SYSTK_CONFIG_H_

/*
 * Bit 2 CLKSOURCE: Clock source selection
 *
 * options=
 * 		STK_AHB_DIV8
 * 		STK_AHB
 * */
#define SYS_CLK_CONG  STK_AHB_DIV8

/* INT En bit 0
 * En --> ENABLE
 * Dis --> DISABLE
 */
#define SYSTICK_INT_DISABLE    ENABLE
#define SYSTICK_INT_ENABLE     DISABLE


/**
 * Choose the system clock source from the available options.
 *
 * Options:
 * - RCC_HSI: Internal High-Speed oscillator (default)
 * - RCC_HSE: External High-Speed oscillator
 * - RCC_PLL: Phase-Locked Loop
 */
#define RCC_SYSCLK             RCC_HSI


#endif /* REPO_MCAL_SYSTK_SYSTK_CONFIG_H_ */
