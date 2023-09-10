/*
 * SYSTK_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: khale
 */

#ifndef REPO_MCAL_SYSTK_SYSTK_INTERFACE_H_
#define REPO_MCAL_SYSTK_SYSTK_INTERFACE_H_


/*
 * Bit 2: CLKSOURCE - Clock source selection
 * Bit 1: TICKINT   - SysTick exception request enable
 * Bit 0: ENABLE    - Counter enable
 */

/** Function to initialize the System Timer
 * Check CLK source in configuration */

void STK_voidInit(void);

/** Function to enable or disable the SysTick interrupt
 * Check ENABLE bit in configuration */
void STK_voidInterruptState(void);

/** Function to start the System Timer with a specified preload value */
void STK_voidStart (u32 Copy_u32PreloadValue );

/** Function to read the SysTick count flag in the Control and Status Register (CTRL)
 * Returns 1 if the count flag is set, 0 if not */
u8 STK_u8ReadFlag(void);

/** Function to get the remaining time for the System Timer to reach zero
 * Returns a 24-bit value (u32) */
u32 STK_u32GetRemainingTime(void);

/** Function to get the elapsed time since the System Timer started
 * Returns a 24-bit value (u32) */
u32 STK_u32GetElapsedTime  (void);

/** Function to implement a delay in microseconds using the System Timer */
void STK_voidDelayUsec(u32 Copy_u32DelayUsec);

/** Function to implement a delay in milliseconds using the System Timer */
void STK_voidDelayMsec(u32 copy_u32DelayMsec);

/** Function to set a callback function to be executed when SysTick interrupt occurs */
void STK_voidSetCallBack(void (*ptr)(void));

void STK_voidSetIntervalPeriodic (u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));



#endif /* REPO_MCAL_SYSTK_SYSTK_INTERFACE_H_ */
