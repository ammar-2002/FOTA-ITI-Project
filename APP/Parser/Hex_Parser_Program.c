/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 9_9_2023                                                                     */
/* Description       : Hex_Parser_Program.c                                             */
/* Features          : contain all Function Implementation                                                           */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                             */
/*******************************************************************************************************/

#include"../../MCAL/SYSTK/SYSTK_Interface.h"
#include"../../MCAL/RCC_Driver/RCC_Interface.h"
#include"../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include"../../MCAL/FLASH/FLASH_Interface.h""
/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      HAL Components                                                */



/********************************************************************************************************/
/*										important macro and array										*/
#define FLASH_BASE_ADDRESS 0x08000000
u16 DataBuffer[];
/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- HexParser_u8AsciiToHex                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to convert data from ascii to hex                             */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Copy_u8Ascii                                                   */
/* 3- Function Return      -> Local_parser                                                                 */
/*******************************************************************************************************/

static u8 HexParser_u8AsciiToHex(u8 Copy_u8Ascii)
{
	u8 Local_parser=0;
	if((Copy_u8Ascii<='0') && (Copy_u8Ascii<='9'))
	{
		Local_parser =Copy_u8Ascii-'0';
	}
	else if((Copy_u8Ascii<='A') && (Copy_u8Ascii<='F'))
	{
		Local_parser =Copy_u8Ascii-55;
	}
	return Local_parser;
}

/*******************************************************************************************************/
/*                                      02- HexParser_voidParseData                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to parsedata and write it to flash                           */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> A_u8ptrData[]                                                   */
/* 3- Function Return      -> nothing                                                                 */
/*******************************************************************************************************/

void HexParser_voidParseData(u8 A_u8ptrData[])
{
	u8 i=0;
	/*character count vatiables*/
	u8 CC_High, CC_Low, CC;
	/*4 digit for coverstion*/
	u8 Digit0,Digit1,Digit2,Digit3;
	/*variable address*/
	u8 Address;
	CC_High = HexParser_u8AsciiToHex(A_u8ptrData[1]);
	CC_Low  = HexParser_u8AsciiToHex(A_u8ptrData[2]);
	CC	    =(CC_High<<4)|CC_Low;

	Digit0 = HexParser_u8AsciiToHex(A_u8ptrData[3]);
	Digit1 = HexParser_u8AsciiToHex(A_u8ptrData[4]);
	Digit2 = HexParser_u8AsciiToHex(A_u8ptrData[5]);
	Digit3 = HexParser_u8AsciiToHex(A_u8ptrData[6]);

	Address = (FLASH_BASE_ADDRESS) | (Digit0<<12) | (Digit1<<8) | (Digit2<<4)| (Digit3);

	for(i=0;i<(CC/2);i++)
	{
		Digit0 = HexParser_u8AsciiToHex(A_u8ptrData[(4*i)+9]);
		Digit1 = HexParser_u8AsciiToHex(A_u8ptrData[(4*i)+10]);
		Digit2 = HexParser_u8AsciiToHex(A_u8ptrData[(4*i)+11]);
		Digit3 = HexParser_u8AsciiToHex(A_u8ptrData[(4*i)+12]);
		DataBuffer[i]=(Digit0<<12) | (Digit1<<8) | (Digit2<<4) |(Digit3);
	}
	MFDI_voidFlashWrite(Address,DataBuffer,CC/2);
}
