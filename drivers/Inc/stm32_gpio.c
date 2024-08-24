/*
 * stm32_gpio.c
 *
 *  Created on: Aug 24, 2024
 *      Author: nhatminh
 */

#include "stm32_gpio.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EN_DIS)
{
	if(EN_DIS == ENABLE)
	{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}
		if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}
		if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}
		if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}
		if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}
		if(pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
	}
	else
	{

	}
}
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	//Enable peripheral clock

	//Configure GPIO Pin mode
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)	//Normal mode
	{
		temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle -> pGPIOx -> MODER &= ~(0x3 << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber)); //reset
		pGPIOHandle -> pGPIOx -> MODER |= temp;
	}
	else //Interrupt mode
	{

	}
	//Configure Speed
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> OSPEEDR &= ~(0x3 << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> OSPEEDR |= temp;
	//Configure Pull up Pull down
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> PUPDR &= ~(0x3 << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> PUPDR |= temp;
	//Configure Output type
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinOType << (pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> OTYPER &= ~(0x1 << (pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> OTYPER |= temp;
	//Configure Alternate function
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

void GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EN_DIS);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
