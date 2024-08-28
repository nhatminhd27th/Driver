#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

#include<stdint.h>

#define FLASH_BASEADDR 	0x08000000U
#define SRAM1_BASEADDR 	0x20000000U
#define ROM_BASEADDR 	0x1FFF0000U
#define SRAM 			SRAM1_BASEADDR

#define PERIPH_BASEADDR 	0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADD
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U

//AHB1
#define GPIOA_BASEADDR	( AHB1PERIPH_BASEADDR + 0x0000 )
#define GPIOB_BASEADDR	( AHB1PERIPH_BASEADDR + 0x0400 )
#define GPIOC_BASEADDR	( AHB1PERIPH_BASEADDR + 0x0800 )
#define GPIOD_BASEADDR	( AHB1PERIPH_BASEADDR + 0x0C00 )
#define GPIOE_BASEADDR	( AHB1PERIPH_BASEADDR + 0x1000 )
#define GPIOH_BASEADDR	( AHB1PERIPH_BASEADDR + 0x1C00 )
#define RCC_BASEADDR	( AHB1PERIPH_BASEADDR + 0x3800 )
#define DMA2_BASEADDR	( APB1PERIPH_BASEADDR + 0x6400 )
#define DMA1_BASEADDR	( APB1PERIPH_BASEADDR + 0x6000 )

//APB2
#define TIM1_BASEADDR 	( APB2PERIPH_BASEADDR + 0x0000 )
#define USART1_BASEADDR ( APB2PERIPH_BASEADDR + 0x1000 )
#define USART6_BASEADDR ( APB2PERIPH_BASEADDR + 0x1400 )
#define ADC1_BASEADDR 	( APB2PERIPH_BASEADDR + 0x2000 )
#define SPI1_BASEADDR 	( APB2PERIPH_BASEADDR + 0x3000 )
#define SPI4_BASEADDR 	( APB2PERIPH_BASEADDR + 0x3400 )
#define SYSCFG_BASEADDR ( APB2PERIPH_BASEADDR + 0x3800 )
#define EXTI_BASEADDR 	( APB2PERIPH_BASEADDR + 0x3C00 )
#define TIM9_BASEADDR 	( APB2PERIPH_BASEADDR + 0x4000 )
#define TIM10_BASEADDR 	( APB2PERIPH_BASEADDR + 0x4400 )
#define TIM11_BASEADDR 	( APB2PERIPH_BASEADDR + 0x4800 )
#define SPI5_BASEADDR 	( APB2PERIPH_BASEADDR + 0x5000 )

//APB1
#define I2C3_BASEADDR  	(APB1PERIPH_BASEADDR + 0x5C00)
#define I2C2_BASEADDR 	(APB1PERIPH_BASEADDR + 0x5800)
#define I2C1_BASEADDR 	(APB1PERIPH_BASEADDR + 0x5400)
#define USART2_BASEADDR (APB1PERIPH_BASEADDR + 0x4400)
#define SPI3_BASEADDR 	(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI2_BASEADDR 	(APB1PERIPH_BASEADDR + 0x3800)
#define TIM5_BASEADDR 	(APB1PERIPH_BASEADDR + 0x0C00)
#define TIM4_BASEADDR 	(APB1PERIPH_BASEADDR + 0x0800)
#define TIM3_BASEADDR 	(APB1PERIPH_BASEADDR + 0x0400)
#define TIM2_BASEADDR 	(APB1PERIPH_BASEADDR + 0x0000)

#define SELECT_PORT(x)	((x = GPIOA)? 0: (x = GPIOB)? 1: (x = GPIOC)? 2: (x = GPIOD)? 3: (x = GPIOE)? 4: (x = GPIOH)? 5: 0)

typedef struct
{
	volatile uint32_t MODER; //thanh ghi 32 bits nen dung uint32_t
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
}GPIO_RegDef_t;

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASEADDR)

typedef struct
{
	volatile uint32_t CR;			//Address offset: 0x00
	volatile uint32_t PLLCFGR;		//Address offset: 0x04
	volatile uint32_t CFGR;			//Address offset: 0x08
	volatile uint32_t CIR;			//Address offset: 0x0C
	volatile uint32_t AHB1RSTR;		//Address offset: 0x10
	volatile uint32_t AHB2RSTR;		//Address offset: 0x14
	volatile uint32_t reserved0;	//Address offset: 0x18
	volatile uint32_t reserved1;	//Address offset: 0x1C
	volatile uint32_t APB1RSTR;		//Address offset: 0x20
	volatile uint32_t APB2RSTR;		//Address offset: 0x24
	volatile uint32_t reserved3;	//Address offset: 0x28
	volatile uint32_t reserved4;	//Address offset: 0x2C
	volatile uint32_t AHB1ENR;		//Address offset: 0x30
	volatile uint32_t AHB2ENR;		//Address offset: 0x34
	volatile uint32_t reserved5;	//Address offset: 0x38
	volatile uint32_t reserved6;	//Address offset: 0x3C
	volatile uint32_t APB1ENR;		//Address offset: 0x40
	volatile uint32_t APB2ENR;		//Address offset: 0x44
	volatile uint32_t reserved7;	//Address offset: 0x48
	volatile uint32_t reserved8;	//Address offset: 0x4C
	volatile uint32_t AHB1LPENR;	//Address offset: 0x50
	volatile uint32_t AHB2LPENR;	//Address offset: 0x54
	volatile uint32_t reserved9;	//Address offset: 0x58
	volatile uint32_t reserved10;	//Address offset: 0x5C
	volatile uint32_t APB1LPENR;	//Address offset: 0x60
	volatile uint32_t APB2LPENR;	//Address offset: 0x64
	volatile uint32_t reserved11;	//Address offset: 0x68
	volatile uint32_t reserved12;	//Address offset: 0x6C
	volatile uint32_t BDCR;			//Address offset: 0x70
	volatile uint32_t CSR;			//Address offset: 0x74
	volatile uint32_t reserved13;	//Address offset: 0x78
	volatile uint32_t reserved14;	//Address offset: 0x7C
	volatile uint32_t SSCGR;		//Address offset: 0x80
	volatile uint32_t PLLI2SCFGR;	//Address offset: 0x84
	volatile uint32_t reserved15;	//Address offset: 0x88
	volatile uint32_t DCKCFGR;		//Address offset: 0x8C

}RCC_RegDef_t;

#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

typedef struct
{
	volatile uint32_t IMR;			//Address offset: 0x00
	volatile uint32_t EMR;			//Address offset: 0x04
	volatile uint32_t RTSR;			//Address offset: 0x08
	volatile uint32_t FTSR;			//Address offset: 0x0C
	volatile uint32_t SWIER;		//Address offset: 0x10
	volatile uint32_t PR;			//Address offset: 0x14
}EXTI_RegDef_t;

#define EXTI ((EXTI_RegDef_t *)EXTI_BASEADDR)

typedef struct
{
	volatile uint32_t LISR;			//Address offset: 0x0000
	volatile uint32_t HISR;			//Address offset: 0x0004
	volatile uint32_t LIFCR;		//Address offset: 0x0008
	volatile uint32_t HIFCR;		//Address offset: 0x000C
	volatile uint32_t S0CR;			//Address offset: 0x0010
	volatile uint32_t S0NDTR;		//Address offset: 0x0014
	volatile uint32_t S0PAR;		//Address offset: 0x0018
	volatile uint32_t S0M0AR;		//Address offset: 0x001C
	volatile uint32_t S0M1AR;		//Address offset: 0x0020
	volatile uint32_t S0FCR;		//Address offset: 0x0024
	volatile uint32_t S1CR;			//Address offset: 0x0028
	volatile uint32_t S1NDTR;		//Address offset: 0x002C
	volatile uint32_t S1PAR;		//Address offset: 0x0030
	volatile uint32_t S1M0AR;		//Address offset: 0x0034
	volatile uint32_t S1M1AR;		//Address offset: 0x0038
	volatile uint32_t S1FCR;		//Address offset: 0x003C
	volatile uint32_t S2CR;			//Address offset: 0x0040
	volatile uint32_t S2NDTR;		//Address offset: 0x0044
	volatile uint32_t S2PAR;		//Address offset: 0x0048
	volatile uint32_t S2M0AR;		//Address offset: 0x004C
	volatile uint32_t S2M1AR;		//Address offset: 0x0050
	volatile uint32_t S2FCR;		//Address offset: 0x0054
	volatile uint32_t S3CR;			//Address offset: 0x0058
	volatile uint32_t S3NDTR;		//Address offset: 0x005C
	volatile uint32_t S3PAR;		//Address offset: 0x0060
	volatile uint32_t S3M0AR;		//Address offset: 0x0064
	volatile uint32_t S3M1AR;		//Address offset: 0x0068
	volatile uint32_t S3FCR;		//Address offset: 0x006C
	volatile uint32_t S4CR;			//Address offset: 0x0070
	volatile uint32_t S4NDTR;		//Address offset: 0x0074
	volatile uint32_t S4PAR;		//Address offset: 0x0078
	volatile uint32_t S4M0AR;		//Address offset: 0x007C
	volatile uint32_t S4M1AR;		//Address offset: 0x0080
	volatile uint32_t S4FCR;		//Address offset: 0x0084
	volatile uint32_t S5CR;			//Address offset: 0x0088
	volatile uint32_t S5NDTR;		//Address offset: 0x008C
	volatile uint32_t S5PAR;		//Address offset: 0x0090
	volatile uint32_t S5M0AR;		//Address offset: 0x0094
	volatile uint32_t S5M1AR;		//Address offset: 0x0098
	volatile uint32_t S5FCR;		//Address offset: 0x009C
	volatile uint32_t S6CR;			//Address offset: 0x00A0
	volatile uint32_t S6NDTR;		//Address offset: 0x00A4
	volatile uint32_t S6PAR;		//Address offset: 0x00A8
	volatile uint32_t S6M0AR;		//Address offset: 0x00AC
	volatile uint32_t S6M1AR;		//Address offset: 0x00B0
	volatile uint32_t S6FCR;		//Address offset: 0x00B4
	volatile uint32_t S7CR;			//Address offset: 0x00B8
	volatile uint32_t S7NDTR;		//Address offset: 0x00BC
	volatile uint32_t S7PAR;		//Address offset: 0x00C0
	volatile uint32_t S7M0AR;		//Address offset: 0x00C4
	volatile uint32_t S7M1AR;		//Address offset: 0x00C8
	volatile uint32_t S7FCR;		//Address offset: 0x00CC
}DMA_RegDef_t;

#define DMA1 ((DMA_RegDef_t *)DMA1_BASEADDR)
#define DMA2 ((DMA_RegDef_t *)DMA2_BASEADDR)

typedef struct
{
	volatile uint32_t CR1;			//Address offset: 0x00
	volatile uint32_t SR;			//Address offset: 0x08
	volatile uint32_t DR;			//Address offset: 0x0C
	volatile uint32_t CRCPR;		//Address offset: 0x10
	volatile uint32_t RXCRCR;		//Address offset: 0x14
	volatile uint32_t TXCRCR;		//Address offset: 0x18
	volatile uint32_t I2SCFGR;		//Address offset: 0x1C
	volatile uint32_t I2SPR;		//Address offset: 0x20
}SPI_RegDef_t;

#define SPI1 ((SPI_RegDef_t *)SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t *)SPI2_BASEADDR)
#define SPI3 ((SPI_RegDef_t *)SPI3_BASEADDR)
#define SPI4 ((SPI_RegDef_t *)SPI4_BASEADDR)
#define SPI5 ((SPI_RegDef_t *)SPI5_BASEADDR)

typedef struct
{
	volatile uint32_t MEMRMP;		//Address offset: 0x00
	volatile uint32_t PMC;			//Address offset: 0x04
	volatile uint32_t EXTICR1;		//Address offset: 0x08
	volatile uint32_t EXTICR2;		//Address offset: 0x0C
	volatile uint32_t EXTICR3;		//Address offset: 0x10
	volatile uint32_t EXTICR4;		//Address offset: 0x04
	volatile uint32_t CMPCR;		//Address offset: 0x20
}SYSCFG_RegDef_t;

#define SYSCFG ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

typedef struct
{
	volatile uint32_t CR1;		//Address offset: 0x00
	volatile uint32_t CR2;		//Address offset: 0x04
	volatile uint32_t OAR1;		//Address offset: 0x08
	volatile uint32_t OAR2;		//Address offset: 0x0C
	volatile uint32_t DR;		//Address offset: 0x10
	volatile uint32_t SR1;		//Address offset: 0x14
	volatile uint32_t SR2;		//Address offset: 0x18
	volatile uint32_t CCR;		//Address offset: 0x1C
	volatile uint32_t TRISE;	//Address offset: 0x20
	volatile uint32_t FLTR;		//Address offset: 0x24
}I2C_RegDef;

#define I2C1 ((I2C_RegDef_t *)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t *)I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t *)I2C3_BASEADDR)

typedef struct
{
	volatile uint32_t SR;		//Address offset: 0x00
	volatile uint32_t DR;		//Address offset: 0x04
	volatile uint32_t BRR;		//Address offset: 0x08
	volatile uint32_t CR1;		//Address offset: 0x0C
	volatile uint32_t CR2;		//Address offset: 0x10
	volatile uint32_t CR3;		//Address offset: 0x14
	volatile uint32_t GTPR;		//Address offset: 0x18
}USART_RegDef_t;

#define USART1 ((USART_RegDef_t *)USART1_BASEADDR)
#define USART2 ((USART_RegDef_t *)USART2_BASEADDR)
#define USART6 ((USART_RegDef_t *)USART6_BASEADDR)

/*
 * Clock enable macro for GPIO peripheral
 */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7))

/*
 * Clock enable macro for I2C peripheral
 */
#define I2C1_PCLK_EN() 	(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() 	(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() 	(RCC->APB1ENR |= (1 << 23))

/*
 * Clock enable macro for SPI peripheral
 */
#define SPI1_PCLK_EN() 	(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() 	(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()	(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() 	(RCC->APB2ENR |= (1 << 13))
#define SPI5_PCLK_EN() 	(RCC->APB2ENR |= (1 << 20))

/*
 * Clock enable macro for USART peripheral
 */
#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() 	(RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()	(RCC->APB2ENR |= (1 << 5))

/*
 * Clock enable macro for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN()	(RCC->APB2ENR |= (1 << 14))

/*
 * Clock disable macro for GPIO peripherals
 */
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 0))
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 1))
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 2))
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 3))
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 4))
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 7))

/*
 * Clock disable macro for I2C peripherals
 */
#define I2C1_PCLK_DI() 	(RCC->APB1ENR &=~ (1 << 21))
#define I2C2_PCLK_DI() 	(RCC->APB1ENR &=~ (1 << 22))
#define I2C3_PCLK_DI() 	(RCC->APB1ENR &=~ (1 << 23))

/*
 * Clock disable macro for SPI peripherals
 */
#define SPI1_PCLK_DI() 	(RCC->APB2ENR &=~ (1 << 12))
#define SPI2_PCLK_DI() 	(RCC->APB1ENR &=~ (1 << 14))
#define SPI3_PCLK_DI()	(RCC->APB1ENR &=~ (1 << 15))
#define SPI4_PCLK_DI() 	(RCC->APB2ENR &=~ (1 << 13))
#define SPI5_PCLK_DI() 	(RCC->APB2ENR &=~ (1 << 20))

/*
 * Clock disable macro for USART peripherals
 */
#define USART1_PCLK_DI()	(RCC->APB2ENR &=~ (1 << 4))
#define USART2_PCLK_DI() 	(RCC->APB1ENR &=~ (1 << 17))
#define USART6_PCLK_DI()	(RCC->APB2ENR &=~ (1 << 5))

/*
 * Clock disable macro for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI()	(RCC->APB2ENR &=~ (1 << 14))

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET 	RESET
#define FLAG_SET 		SET
#define FLAG_RESET 		RESET

#define GPIOA_REG_RESET(){\
	(RCC->AHB1RSTR |= (1<<0));\
	(RCC->AHB1RSTR &= ~(1<<0));\
}

#define GPIOB_REG_RESET(){\
	(RCC->AHB1RSTR |= (1<<1));\
	(RCC->AHB1RSTR &= ~(1<<1));\
}

#define GPIOC_REG_RESET(){\
	(RCC->AHB1RSTR |= (1<<2));\
	(RCC->AHB1RSTR &= ~(1<<2));\
}

#define GPIOD_REG_RESET(){\
	(RCC->AHB1RSTR |= (1<<3));\
	(RCC->AHB1RSTR &= ~(1<<3));\
}

#define GPIOE_REG_RESET(){\
	(RCC->AHB1RSTR |= (1<<4));\
	(RCC->AHB1RSTR &= ~(1<<4));\
}

#define GPIOH_REG_RESET(){\
	(RCC->AHB1RSTR |= (1<<7));\
	(RCC->AHB1RSTR &= ~(1<<7));\
}

#endif
