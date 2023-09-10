/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 2_9_2023                                                                     */
/* Description       : LCD_Program.c                                             */
/* Features          : Functions implementations                                                            */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATHS.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                             */
/*******************************************************************************************************/

#include"SYSTK/SYSTK_Interface.h"

#include"GPIO/GPIO_Interface.h"
/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      HAL Components                                                */
#include"LCD_Interface.h"
#include"LCD_Config.h"
#include"LCD_Private.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- LCD_voidInit                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to inilize lcd                             */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> Nothing                                                   */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidInit(void)
{
	u8 i=0;
	/********************************** select lcd pins as output  ***********************************/
	for(i=0;i<11;i++)
	{
		GPIO_u8SetPinMode(PORT_NAME,i,GPIO_u8_PinModeOutput); /*select pins as output pins*/
		GPIO_u8SetPinOutputType(PORT_NAME,i,GPIO_u8_OP_OP); /*select push pull output type*/
		GPIO_u8SetPinOutputSpeed(PORT_NAME,i,GPIO_u8_MODE_LS); /*select gpio low speed*/
		GPIO_u8SetPinPullMode(PORT_NAME,i,GPIO_u8_PP);/*select pull up output pins*/
	}
	STK_voidDelayMsec(10);
	/*select lcd write data mode */
	GPIO_u8ChangePinOutMode(PORT_NAME,RW,GPIO_u8_OP_MODE_RESET);
	LCD_voidSendCmd(0x33);
	LCD_voidSendCmd(0x32);
	STK_voidDelayMsec(2);
	/*select 8 bit mode*/
	LCD_voidSendCmd(EIGHT_BITS);
	STK_voidDelayMsec(2);
	/*disp;ay on cursor on command*/
	LCD_voidSendCmd(Disply_On_Cursor_On);
	STK_voidDelayMsec(2);
	/*clear dispaly*/
	LCD_voidSendCmd(Clear_Display_Screen);
	STK_voidDelayMsec(10);
	/*select entry mode*/
	LCD_voidSendCmd(Entry_Mode);
	STK_voidDelayMsec(5);
}

/*******************************************************************************************************/
/*                                      02- LCD_voidSendFallingEdge                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send falling edge to enable bit to enable LCD                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
static void LCD_voidSendFallingEdge(void)
{
	GPIO_u8ChangePinOutMode(PORT_NAME,EN,GPIO_u8_OP_MODE_SET);
	STK_voidDelayMsec(3);
	GPIO_u8ChangePinOutMode(PORT_NAME,EN,GPIO_u8_OP_MODE_RESET);
	STK_voidDelayMsec(3);
}

/*******************************************************************************************************/
/*                                      03- LCD_voidSendCmd                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send command to                             */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Copy_u8Cmd                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidSendCmd(u8 Copy_u8Cmd)
{
	u8 i;
	/*send LOW to RS pin because i send command*/
	GPIO_u8ChangePinOutMode(PORT_NAME,RS,GPIO_u8_OP_MODE_RESET);
	/*loop untial send cmd*/
	for(i=0;i<=7;i++)
	{
		(GET_BIT(Copy_u8Cmd,i)) ? GPIO_u8ChangePinOutMode(PORT_NAME,i,GPIO_u8_OP_MODE_SET) : GPIO_u8ChangePinOutMode(PORT_NAME,i,GPIO_u8_OP_MODE_RESET);
	}
	/*send falling edge to enable lcd display */
	LCD_voidSendFallingEdge();
}

/*******************************************************************************************************/
/*                                      04- LCD_voidSendChar                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send charachter to lcd                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Copy_u8Data                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidSendChar(u8 Copy_u8Data)
{
	u8 i;
	/*send LOW to RS pin because i send data*/
	GPIO_u8ChangePinOutMode(PORT_NAME,RS,GPIO_u8_OP_MODE_SET);
	/*loop untial send data*/
	for(i=0;i<=7;i++)
	{
		(GET_BIT(Copy_u8Data,i)) ? GPIO_u8ChangePinOutMode(PORT_NAME,i,GPIO_u8_OP_MODE_SET) : GPIO_u8ChangePinOutMode(PORT_NAME,i,GPIO_u8_OP_MODE_RESET);
	}
	/*send falling edge to enable lcd dispaly */
	LCD_voidSendFallingEdge();
}

/*******************************************************************************************************/
/*                                      05- LCD_voidSendString                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send string  to lcd                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Copy_ptrData                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidSendString(u8 *Copy_ptrData)
{
	while((*Copy_ptrData)!='\0')
	{
		LCD_voidSendChar(*Copy_ptrData);
		Copy_ptrData++;
	}
}

/*******************************************************************************************************/
/*                                      06- LCD_voidClearScreen                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to clear screen of lcd                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidClearScreen(void)
{
	LCD_voidSendCmd(Clear_Display_Screen);
	STK_voidDelayMsec(10);

}

/*******************************************************************************************************/
/*                                      07- LCD_voidMoveCursor                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to move cursor to sepcific position on lcd screen                             */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidMoveCursor(u8 Copy_u8Row,u8 Copy_u8Coloumn)
{
	u8 data=0 ;
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Row>16||Copy_u8Coloumn<1)
	{
		data=Force_Cursor_To_Beginning_Of_1st_Line;
	}
	else if(Copy_u8Row==1)
	{
		data=Force_Cursor_To_Beginning_Of_1st_Line+Copy_u8Coloumn-1 ;
	}
	else if (Copy_u8Row==2)
	{
		data=Force_Cursor_To_Beginning_Of_2nd_Line+Copy_u8Coloumn-1;
	}
	LCD_voidSendCmd(data);
	STK_voidDelayMsec(2);
}

