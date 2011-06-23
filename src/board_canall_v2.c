/*
 * board_canall_v2.c
 *
 *  Created on: Mar 30, 2011
 *      Author: nx
 */

#include "main.h"
#include "board_canall_v2.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"


void InitBoardCanall (void) {
	GPIO_InitTypeDef GPIO_InitStruct;
	//  	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0);
	  	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPAEN, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1ENR_CAN1EN, ENABLE);

	// 	GPIO_StructInit(&GPIO_InitStruct);
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 + GPIO_Pin_1 + GPIO_Pin_2 + GPIO_Pin_3
								 + GPIO_Pin_4 + GPIO_Pin_5 + GPIO_Pin_6 + GPIO_Pin_7; 		// OUT1 - OUT8
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	  	GPIO_Init(GPIOA, &GPIO_InitStruct);

	  	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10												// USART-TX
								 + GPIO_Pin_12												// CAN-TD1
								 + GPIO_Pin_13;												// SWDIO
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	  	GPIO_Init(GPIOA, &GPIO_InitStruct);

	  	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8												// IOCOMLV
								 + GPIO_Pin_9												// USART-RX
								 + GPIO_Pin_11												// CAN-RD1
								 + GPIO_Pin_14												// SWCLK
								 + GPIO_Pin_15;												// IN8
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	  	GPIO_Init(GPIOA, &GPIO_InitStruct);

//-----------------------------------------------------------------------------------------------------------------
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	                                // NX: AFIO clock enabled
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);							// NX: disable JTAG-DP enabLe SWDP
//-----------------------------------------------------------------------------------------------------------------
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0												// IN1
								 + GPIO_Pin_1												// IN2
								 + GPIO_Pin_2												// BOOT1
								 + GPIO_Pin_4												// JNTRST
								 + GPIO_Pin_5												// IN3
								 + GPIO_Pin_6												// I2C1_SCL
								 + GPIO_Pin_7												// I2C1_SDA
								 + GPIO_Pin_8												// IN4
								 + GPIO_Pin_9												// IN5
								 + GPIO_Pin_10												// IN6
								 + GPIO_Pin_3  + GPIO_Pin_11  + GPIO_Pin_12
		 	 	 	 	 	 	 + GPIO_Pin_13 + GPIO_Pin_14 + GPIO_Pin_15;					// NX: CANALL_V2: DSW6 - DSW1
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	  	GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6; 												// NX: CAN-ENABLE
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOB, &GPIO_InitStruct);


		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 												// NX: LED1
								 + GPIO_Pin_15;												// NX: LED2
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOC, &GPIO_InitStruct);

		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14 ;											// NX: IN7
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_Init(GPIOC, &GPIO_InitStruct);


}
