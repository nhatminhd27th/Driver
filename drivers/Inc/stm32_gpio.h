/*
 * stm32_gpio.h
 *
 *  Created on: Aug 24, 2024
 *      Author: OS
 */

#ifndef INC_STM32_GPIO_H_
#define INC_STM32_GPIO_H_

#include<stm32f4.h>

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOType;
	uint8_t GPIO_PinAltFuntionMode;
}GPIO_PinConfig_t;

typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

#define GPIO_PIN_0 	0
#define GPIO_PIN_1 	1
#define GPIO_PIN_2 	2
#define GPIO_PIN_3 	3
#define GPIO_PIN_4 	4
#define GPIO_PIN_5 	5
#define GPIO_PIN_6 	6
#define GPIO_PIN_7 	7
#define GPIO_PIN_8 	8
#define GPIO_PIN_9 	9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15

#define GPIO_MODE_IN		0	//Input mode
#define GPIO_MODE_OUT		1	//Output mode
#define GPIO_MODE_ALT		2	//Alternate function mode
#define GPIO_MODE_ANALOG	3	//Analog mode
#define GPIO_MODE_IT_FE		4	//Falling Edge
#define GPIO_MODE_IT_RE		5	//Rising Edge
#define GPIO_MODE_IT_FRE	6	//Falling and Rising Edge

#define GPIO_OP_TYPE_PP 	0	//Puss-Pull
#define GPIO_OP_TYPE_OD 	1	//Open drain

#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGHT	3

#define GPIO_NO_PP			0
#define GPIO_NO_PU			1
#define GPIO_NO_PD			2

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EN_DIS);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EN_DIS);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32_GPIO_H_ */
