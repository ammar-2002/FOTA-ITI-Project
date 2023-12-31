/*
 * STD_TYPES.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Ammar
 */

#ifndef APP_LIB_STD_TYPES_H_
#define APP_LIB_STD_TYPES_H_

typedef unsigned  char       u8;
typedef signed    char       s8;
typedef unsigned short int   u16;
typedef signed   short int   s16;
typedef unsigned long  int   u32;
typedef signed   long  int   s32;
typedef float                f32;
typedef double               f64;

typedef enum{
	BIT_RESET =0,
	BIT_SET=1
}BitStatus;

#define NULL ((void*)0)

#define STD_TYPES_OK 	1;
#define STD_TYPES_NOK 	0;

#endif /* APP_LIB_STD_TYPES_H_ */
