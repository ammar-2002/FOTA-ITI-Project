/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 2_9_2023                                                                     */
/* Description       : FLASH_Private.h                                            */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file                    							       */
/*******************************************************************************************************/

#ifndef REPO_MCAL_FLASH_FLASH_PRIVATE_H_
#define REPO_MCAL_FLASH_FLASH_PRIVATE_H_

#define FALSH_BASE_ADDRESS   0x40023C00

#define PROGRAM_ERACE_KEY1   0x45670123
#define PROGRAM_ERACE_KEY2   0x45670123

#define SECTOR0     0x08000000
#define SECTOR1     0x08004000
#define SECTOR2     0x08008000
#define SECTOR3     0x0800C000
#define SECTOR4     0x08010000
#define SECTOR5     0x08020000 

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                 */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*                                                                                                     */
/*******************************************************************************************************/
typedef struct
{

    volatile u32 FLASH_ACR;
    volatile u32 FLASH_KEYR;
    volatile u32 FLASH_OPTKEYR;
    volatile u32 FLASH_SR;
    volatile u32 FLASH_CR;
    volatile u32 FLASH_OPTCR;
}FLASH_t;

#define FLASH ((FLASH_t*)FALSH_BASE_ADDRESS)

#endif /* REPO_MCAL_FLASH_FLASH_PRIVATE_H_ */
