/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 9_9_2023                                                                     */
/* Description       : LCD_Interface.h                                             */
/* Features          : contain all Function Prototypes and another important macros                                                           */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file                    							       */
/*******************************************************************************************************/
#ifndef REPO_HAL_LCD_LCD_INTERFACE_H_
#define REPO_HAL_LCD_LCD_INTERFACE_H_

#define PORT1	GPIOA
#define PORT2	GPIOB
/* All  LCD Commands */
#define Clear_Display_Screen  			       0x01
#define Return_Home            			       0x02
#define Shift_Cursor_To_Left  			       0x04
#define Shift_Cursor_To_Right 		           0x06
#define Shift_Display_Right   			       0x05
#define Shift_Display_Left    			       0x07
#define Disply_Off_Cursor_Off			       0x08
#define Disply_Off_Cursor_On  			       0x0A
#define Disply_On_Cursor_Off  			       0x0c
#define Disply_On_Cursor_On  			       0x0e
#define Disply_On_Cursor_Blinking          	   0x0f
#define Shift_Cursor_Position_To_Left          0x10
#define Shift_Cursor_Position_To_Right         0x14
#define Shift_Entire_Display_To_Left   		   0x18
#define Shift_Entire_Display_To_Right   	   0x1c
#define Force_Cursor_To_Beginning_Of_1st_Line  0x80
#define Force_Cursor_To_Beginning_Of_2nd_Line  0xc0
#define Entry_Mode  						   0x06
#define FOUR_BITS 							   0x28
#define EIGHT_BITS 							   0x38
/*-------------------------------------------------------------------------------------------------*/
/*macros for important LCD pins*/

#define RS 8
#define RW 9
#define EN 10

/*#####################################################################################################*/
 /*                                      Function Prototypes                                            */
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
void LCD_voidInit(void);

/*******************************************************************************************************/
/*                                      02- LCD_voidSendFallingEdge                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send falling edge to enable bit to enable LCD                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
static void LCD_voidSendFallingEdge(void);

/*******************************************************************************************************/
/*                                      03- LCD_voidSendCmd                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send command to                             */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Copy_u8Cmd                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidSendCmd(u8 Copy_u8Cmd);

/*******************************************************************************************************/
/*                                      04- LCD_voidSendChar                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send charachter to lcd                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Copy_u8Data                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidSendChar(u8 Copy_u8Data);

/*******************************************************************************************************/
/*                                      05- LCD_voidSendString                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send string  to lcd                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  Copy_ptrData                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidSendString(u8 *Copy_ptrData);

/*******************************************************************************************************/
/*                                      06- LCD_voidClearScreen                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to clear screen of lcd                            */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidClearScreen(void);

/*******************************************************************************************************/
/*                                      07- LCD_voidMoveCursor                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to move cursor to sepcific position on lcd screen                             */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       ->  nothing                                                  */
/* 3- Function Return      -> NoThing                                                                 */
/*******************************************************************************************************/
void LCD_voidMoveCursor(u8 Copy_u8Row,u8 Copy_u8Coloumn);


#endif /* REPO_HAL_LCD_LCD_INTERFACE_H_ */
