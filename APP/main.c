/********************************************************
AUTHOR  	: AMMAR WAEL
MICRO   	: STM32F401CCU6
LAYER   	: APP
File    	: Main File
Description	: RTOS_TEST
Version 	: 1.0
**********************************************************
*********************************************************/


/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "UART_INTERFACE.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"

/***************************************************************
****************************** APP *****************************
****************************************************************/

int main(void){
	RCC_VoidInit();
	RCC_VoidEnablePeripherals(USART1);
	RCC_VoidEnablePeripherals(GPIOB);
	GPIO_voidSetPinMode(PORTB,PIN_6,ALTERNATE);
	GPIO_voidSetPinMode(PORTB,PIN_7,ALTERNATE);
	GPIO_VSetPinAlternateFunction(PORTB,PIN_6,AF7);
	GPIO_VSetPinAlternateFunction(PORTB,PIN_7,AF7);
	UART_VInit(UART1);
	UART_VSetBuadRate(UART1,9600);
	while(1){
		u16 data = UART_U16RecieveData(UART1);
		if(data == 65){
			UART_VSendData(UART1,(u16)'A');
			for(u32 i=0; i < 1600;i++);
			UART_VSendData(UART1,(u16)'m');
			for(u32 i=0; i < 1600;i++);
			UART_VSendData(UART1,(u16)'m');
			for(u32 i=0; i < 1600;i++);
			UART_VSendData(UART1,(u16)'a');
			for(u32 i=0; i < 1600;i++);
			UART_VSendData(UART1,(u16)'r');
		}
		
	}
}

/*
void LED_0_TOG_TASK(void);
void LED_1_TOG_TASK(void);
void LED_2_TOG_TASK(void);
void LED_3_TOG_TASK(void);
void LED_4_TOG_TASK(void);
void LED_5_TOG_TASK(void);

LED_INIT(LED_0);
	LED_INIT(LED_1);
	LED_INIT(LED_2);
	LED_INIT(LED_3);
	LED_INIT(LED_4);
	LED_INIT(LED_5);
	RTOS_tCreateTask(LED_0_TOG_TASK,10);
	RTOS_tCreateTask(LED_1_TOG_TASK,20);
	RTOS_tCreateTask(LED_2_TOG_TASK,30);
	RTOS_tCreateTask(LED_3_TOG_TASK,40);
	RTOS_tCreateTask(LED_4_TOG_TASK,50);
	RTOS_tCreateTask(LED_5_TOG_TASK,60);
	RTOS_tStartOS();

void LED_0_TOG_TASK(void){
	LED_TOG(LED_0);
}

void LED_1_TOG_TASK(void){
	LED_TOG(LED_1);
}

void LED_2_TOG_TASK(void){
	LED_TOG(LED_2);
}

void LED_3_TOG_TASK(void){
	LED_TOG(LED_3);
}

void LED_4_TOG_TASK(void){
	LED_TOG(LED_4);
}

void LED_5_TOG_TASK(void){
	LED_TOG(LED_5);
}
*/


/*

RCC_VoidInit();
	RCC_VoidEnablePeripherals(GPIOA);
	NVIC_VInterrupt_SetEnable(6);
	NVIC_VInterrupt_SetEnable(7);
	EXTI_VEnableEXTI(EXTI_LINE_0);
	EXTI_VEnableEXTI(EXTI_LINE_1);
	EXTI_VSetExtiConfig(EXTI_LINE_0,EXIT_PORTA);
	EXTI_VSetExtiConfig(EXTI_LINE_1,EXIT_PORTA);
	EXTI_VSetTriggerSource(EXTI_LINE_0,ON_RISING);
	EXTI_VSetTriggerSource(EXTI_LINE_1,ON_RISING);
	GPIO_voidSetPinMode(PORTA,PIN_0,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_1,INPUT);
	GPIO_voidSetInputMode(PORTA,PIN_0,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_1,PULL_DOWN);
	GPIO_voidSetPinMode(PORTA,PIN_2,OUTPUT);
	GPIO_voidChangePinOutValue(PORTA,PIN_2,HIGH);
	EXTI0_VCallBack(LED_ON);
	EXTI1_VCallBack(LED_OFF);
	
*/

/***************************************************************
	************************ Declarations **************************
	****************************************************************
	u8 i;
	u8 display;
	

	***************************************************************
	***************************** INIT *****************************
	****************************************************************

	RCC_VoidInit(); 										*Cloclk init*
	RCC_VoidEnablePeripherals(GPIOA);						*Enabble clock for GPIOA*
	RCC_VoidEnablePeripherals(GPIOB);						*Enabble clock for GPIOB*
	GPIO_voidSetPinMode(PORTA,PIN_0,INPUT);					*Set all pins in GPIOA into INPUT*
	GPIO_voidSetPinMode(PORTA,PIN_1,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_2,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_3,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_4,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_5,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_6,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_7,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_8,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_9,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_10,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_11,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_12,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_13,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_14,INPUT);
	GPIO_voidSetPinMode(PORTA,PIN_15,INPUT);
	GPIO_voidSetInputMode(PORTA,PIN_0,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_1,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_2,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_3,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_4,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_5,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_6,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_7,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_8,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_9,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_10,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_11,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_12,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_13,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_14,PULL_DOWN);
	GPIO_voidSetInputMode(PORTA,PIN_15,PULL_DOWN);
	GPIO_voidSetPinMode(PORTB,PIN_0,OUTPUT);
	GPIO_voidSetPinMode(PORTB,PIN_1,OUTPUT);
	GPIO_voidSetPinMode(PORTB,PIN_2,OUTPUT);
	GPIO_voidSetPinMode(PORTB,PIN_3,OUTPUT);
	while(1){
		i = PIN_0;
		display = 0;
		GPIO_voidChangePinOutValue(PORTB,PIN_0,LOW);
		GPIO_voidChangePinOutValue(PORTB,PIN_1,LOW);
		GPIO_voidChangePinOutValue(PORTB,PIN_2,LOW);
		GPIO_voidChangePinOutValue(PORTB,PIN_3,LOW);
		for(;i <= PIN_15; i++){
			if(GPIO_u8GetPinValue(PORTA,i)){
				display = i;
			}
		}
		if(display & 1){
			GPIO_voidChangePinOutValue(PORTB,PIN_0,HIGH);
		}
		if(display & 2){
			GPIO_voidChangePinOutValue(PORTB,PIN_1,HIGH);
		}
		if(display & 4){
			GPIO_voidChangePinOutValue(PORTB,PIN_2,HIGH);
		}
		if(display & 8){
			GPIO_voidChangePinOutValue(PORTB,PIN_3,HIGH);
		}
	}
	*/
