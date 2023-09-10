/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 2_9_2023                                                                     */
/* Description       : FLASH_Program.c                                             */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include"FLASH_Interface.h"
#include "FLASH_Config.h"
#include "FLASH_Private.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MFDI_voidSectorErase                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function erase a specific sector                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Copy_u8SectorNumber                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MFDI_voidSectorErase(u8 Copy_u8SectorNumber)
{
	/*wait if busy equal 1 in FLASH_CR*/
	while(GET_BIT(FLASH->FLASH_CR,BSY)==1);

	/*unlock FLASH_CR and allow Program and Erase operations*/
	if(GET_BIT(FLASH->FLASH_CR,LOCK)==1)
	{
		FLASH->FLASH_KEYR=PROGRAM_ERACE_KEY1 ;
		FLASH->FLASH_KEYR=PROGRAM_ERACE_KEY2 ;
	}
	/*clear sector bits*/
	CLEAR_BIT(FLASH->FLASH_CR,SNB3);
	CLEAR_BIT(FLASH->FLASH_CR,SNB4);
	CLEAR_BIT(FLASH->FLASH_CR,SNB5);
	CLEAR_BIT(FLASH->FLASH_CR,SNB6);
	/*set sector number*/
	FLASH->FLASH_CR |= (Copy_u8SectorNumber<<3);
	/*Bit 1 SER: Sector Erase*/
	SET_BIT(FLASH->FLASH_CR,SER);

	/*Bit 16 STRT: Start This bit triggers an erase operation when set*/
	SET_BIT(FLASH->FLASH_CR,STRT);

	/*wait if busy equal 1 in FLASH_CR*/
	while(GET_BIT(FLASH->FLASH_CR,BSY)==1);

	/*disable  Sector Erase*/
	CLEAR_BIT(FLASH->FLASH_CR,SER);

}

/*******************************************************************************************************/
/*                                      02- MFDI_voidMassErase                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to mass erase to erase all of flash sectors                      */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void MFDI_voidMassErase(void)
{
	u8 Local_u8Itrator =0;
	for(Local_u8Itrator=0 ;Local_u8Itrator<=5;Local_u8Itrator++)
	{
		MFDI_voidSectorErase(Local_u8Itrator);
	}
}

/*******************************************************************************************************/
/*                                      03- MFDI_voidFlashWrite                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to write flah memory                      */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Copy_u32Addess , *Copy_ptrData,    Copy_u8DataLength                                             */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void MFDI_voidFlashWrite(u32 Copy_u32Addess, u16*Copy_ptrData, u8 Copy_u8DataLength)
{
	u8 counter;
	/*wait if busy equal 1 in FLASH_CR*/
	while(GET_BIT(FLASH->FLASH_CR,BSY)==1);

	/*unlock FLASH_CR and allow Program and Erase operations*/
	if(GET_BIT(FLASH->FLASH_CR,LOCK)==1)
	{
		FLASH->FLASH_KEYR=PROGRAM_ERACE_KEY1 ;
		FLASH->FLASH_KEYR=PROGRAM_ERACE_KEY2 ;
	}

	/*configure data size program x16 */
	FLASH->FLASH_CR &=~(0b11<<8);
	SET_BIT(FLASH->FLASH_CR,PSIZE8);
	CLEAR_BIT(FLASH->FLASH_CR,PSIZE9);


	/*enable PG: Programming bit*/
	SET_BIT(FLASH->FLASH_CR,PG);
	/*loop until write all data length*/
	for(counter=0;counter<Copy_u8DataLength;counter++)
	{
		*(volatile u16*)(Copy_u32Addess)=Copy_ptrData[counter];
		Copy_u32Addess+=2; /*i chosse half word data size*/
		/*wait if busy equal 1 in FLASH_CR*/
		while(GET_BIT(FLASH->FLASH_CR,BSY)==1);
		/*clear End of operation flag*/
		SET_BIT(FLASH->FLASH_SR,EOP);
	}

	/*disable PG: Programming bit*/
	CLEAR_BIT(FLASH->FLASH_CR,PG);
}

