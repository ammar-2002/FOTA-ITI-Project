/*
 * *********************************************************************************************************
 * *********************************************************************************************************
 * GPIO_INTERFACE.h
 *
 *  Created on	: Sep  9, 2023
 *      Author	: Youssef Hussein
 *      File 	: Interface File
 *      Driver  : GPIO
 * *********************************************************************************************************
 * *********************************************************************************************************
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/*Func name:GPIO_u8SetPinMode
 * Description:  configure the I/O direction mode
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinMode:GPIO_u8_PinModeInput:GPIO_u8_PinModeInput
 *													GPIO_u8_PinModeOutput
 *													GPIO_u8_PinModeAF
 *													GPIO_u8_PinModeAnalog
 *				return:Local_Error_state
 *
 *
 */
u8 GPIO_u8SetPinMode(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinMode) ;




/*Func GPIO_u8SetPinOutputType
 * Description: change Port Pin output Type
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinType: GPIO_u8_OP_PP    	//Output push-pull
 * 								GPIO_u8_OP_OP		//Output open-drain
 *
 *
 *
 *				return:Local_Error_state
 *
 *
 */
u8	 GPIO_u8SetPinOutputType(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinType);





/*Func name:GPIO_u8SetPinOutputSpeed
 * Description:configure the I/O output speed
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinSpeed:
 *							 	 GPIO_u8_MODE_LS		    //GPIO PIN Low speed Mode
 *							 	 GPIO_u8_MODE_MS			//GPIO PIN Medium speed Mode
 *							 	 GPIO_u8_MODE_HS			//GPIO PIN high speed Mode
 *							 	 GPIO_u8_MODE_VHS			//GPIO PIN Very high speed Mode
 *
 *				return:Local_Error_state
 *
 *
 */
u8 GPIO_u8SetPinOutputSpeed(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinSpeed);





/*Func name: GPIO_u8SetPinPullMode
 * Description:configure the I/O pull-up or pull-down
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	GPIO_u8_NO_PP_PD			// No pull-up, pull-down
 *								 	GPIO_u8_PP					//Pull-up
 *							 		GPIO_u8_PD					//Pull-down
 *
 *
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinPullMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinPullMode);



/*Func name: GPIO_u8GetPinValue
 * Description: Get Port input data
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 *
 *				return:PinValue
 */
u8 	 GPIO_u8GetPinValue(u8 copy_u8PortId,u8 copy_u8PinId);




/*Func name: GPIO_u8ChangePinOutMode
 * Description: change Port Output data
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	PIO_u8_OP_MODE_RESET		//GPIO PIN Output Reset
 *								 	PIO_u8_OP_MODE_SET			//GPIO PIN Output Set
 *
 *
 *
 *				return:Local_Error_state
 */
u8 GPIO_u8ChangePinOutMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinOutVal);



/*Func name: GPIO_u8DirectSetPinOutMode
 * Description:Direct atomic change of OP Mode
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	GPIO_u8_OP_MODE_RESET		//GPIO PIN Output Reset
 *								 	GPIO_u8_OP_MODE_SET			//GPIO PIN Output Set
 *
 *
 *
 *				return:Local_Error_state
 */
u8 GPIO_u8DirectSetPinOutMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinOutVal);


#define GPIO_u8PortA		0
#define GPIO_u8PortB		1
#define GPIO_u8PortC		2

#define GPIO_u8_PinModeInput	0
#define GPIO_u8_PinModeOutput	1
#define GPIO_u8_PinModeAF		2
#define GPIO_u8_PinModeAnalog	3

#define GPIO_u8_OP_PP		0		//GPIO OPEN DRAIN MODE
#define GPIO_u8_OP_OP		1		//GPIO PUSH PULL  MODE

#define GPIO_u8_MODE_LS			0   //GPIO PIN Low speed Mode
#define GPIO_u8_MODE_MS			1	//GPIO PIN Medium speed Mode
#define GPIO_u8_MODE_HS			2	//GPIO PIN high speed Mode
#define GPIO_u8_MODE_VHS		3	//GPIO PIN Very high speed Mode

#define GPIO_u8_OP_MODE_RESET	0	//GPIO PIN Output Reset
#define GPIO_u8_OP_MODE_SET		1	//GPIO PIN Output Set



//GPIO port pull-up/pull-down Port x configuration bits.
#define GPIO_u8_NO_PP_PD	0		// No pull-up, pull-down
#define GPIO_u8_PP			1		//Pull-up
#define GPIO_u8_PD			2		//Pull-down

#define GPIO_Pin0			0
#define GPIO_Pin1           1
#define GPIO_Pin2           2
#define GPIO_Pin3           3
#define GPIO_Pin4           4
#define GPIO_Pin5           5
#define GPIO_Pin6           6
#define GPIO_Pin7           7
#define GPIO_Pin8           8
#define GPIO_Pin9           9
#define GPIO_Pin10          10
#define GPIO_Pin11          11
#define GPIO_Pin12          12
#define GPIO_Pin13          13
#define GPIO_Pin14          14
#define GPIO_Pin15          15




#endif /* GPIO_INTERFACE_H_ */
