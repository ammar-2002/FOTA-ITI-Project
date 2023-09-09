/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 2_9_2023                                                                     */
/* Description       : FLASH_Interface.h                                             */
/* Features          : R                                                          */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file                    							       */
/*******************************************************************************************************/

#ifndef REPO_MCAL_FLASH_FLASH_INTERFACE_H_
#define REPO_MCAL_FLASH_FLASH_INTERFACE_H_

/* bit marcos for status register */
#define BSY		16 /*Bit 16 BSY: Busy */
#define  EOP     0   /* Bit 0 EOP: End of operation*/



 /*bit macros for control register*/
#define PG		0 /*Bit 0 PG: Programming*/
#define SER		1 /*Bit 1 SER: Sector Erase*/

/* Bits 6:3 SNB[3:0]: Sector number These bits select the sector to erase*/
#define SNB3	3
#define SNB4	4
#define SNB5	5
#define SNB6	6

/*Bits 9:8 PSIZE[1:0]: Program size These bits select the program parallelism*/
#define PSIZE8	8
#define PSIZE9	9

#define STRT	16 /*Bit 16 STRT: Start*/
#define LOCK	31 /*Bit 31 LOCK: Lock*/

/*#####################################################################################################*/
 /*                                      Function Prototypes                                            */
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
void MFDI_voidSectorErase(u8 Copy_u8SectorNumber);

/*******************************************************************************************************/
/*                                      02- MFDI_voidMassErase                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to mass erase to erase all of flash sectors                      */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void MFDI_voidMassErase(void);

/*******************************************************************************************************/
/*                                      03- MFDI_voidFlashWrite                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to write flah memory                      */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Copy_u32Addess , *Copy_ptrData,    Copy_u8DataLength                                             */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void MFDI_voidFlashWrite(u32 Copy_u32Addess,u32*Copy_ptrData,u8 Copy_u8DataLength);


#endif /* REPO_MCAL_FLASH_FLASH_INTERFACE_H_ */
