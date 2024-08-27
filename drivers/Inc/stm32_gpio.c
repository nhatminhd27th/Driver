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
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{

	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//Enable peripheral clock
	GPIO_PeriClockControl(pGPIOHandle -> pGPIOx, ENABLE);
	//Configure GPIO Pin mode
	uint32_t temp = 0;
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
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALT)
	{
		uint8_t temp1, temp2, temp3;
		temp1 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber / 8;	//VD chon chan so 7 -> 7/8 = 0 -> dung AFRL
		temp2 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber % 8;	//VD chon chan so 7 -> 7%8 = 7 -> dich 4*7 bit
		temp3 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinAltFuntionMode << (4 * temp2);
		if(temp1 == 0)
		{
			pGPIOHandle -> pGPIOx -> AFRL &= ~(0xF << temp2);
			pGPIOHandle -> pGPIOx -> AFRL |= temp3;
		}
		else
		{
			pGPIOHandle -> pGPIOx -> AFRH &= ~(0xF << temp2);
			pGPIOHandle -> pGPIOx -> AFRH |= temp3;
		}
	}
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
}

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx -> IDR >> PinNumber) & 0x00000001);
	return value;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx -> IDR;
	return value;
}

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx -> ODR |= (1 << PinNumber);
	}
	else if(Value == GPIO_PIN_SET)
	{
		pGPIOx -> ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx -> ODR = Value;
}


void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx -> ODR ^= (1 << PinNumber);
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EN_DIS);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
