/*
 * BIT_MATH.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Ammar
 */

#ifndef APP_LIB_BIT_MATH_H_
#define APP_LIB_BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= (u32)~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

#endif /* APP_LIB_BIT_MATH_H_ */
