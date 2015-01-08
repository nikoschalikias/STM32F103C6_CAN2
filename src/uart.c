/*********************************************************************
 *
 * UART support - provides UARTx and UARTd support routines
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 *********************************************************************
 * FileName:    uart.c
 * Depends:
 * Processor:   STM32F100RBT6B
 *
 * Author               Date       Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Kubik                16.11.2010 Initial code
 ********************************************************************/

//#include <stddef.h>
//#include <stdio.h>
//#include <sys/unistd.h>
#include "stm32f10x.h"
// NX: #include "STM32_Discovery.h"
#include "debug.h"
#include "uart.h"

//
// UARTx is used by printf
// UARTd is used by debug output (redirected stderr)
//

void InitializeUarts(void) {
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	// Configure peripherals used - enable their clocks
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    // Configure USART1 and USART2 Tx as alternate function push-pull
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // Configure USART1 and USART2 Rx as input floating
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // Prepare parameters first - traditional 115.2 / 8b / no parity, no flow control
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    // Configure and enable UARTx
    USART_Init(UARTx, &USART_InitStructure);
    USART_Cmd(UARTx, ENABLE);

    // Configure and enable UARTd
    USART_Init(UARTd, &USART_InitStructure);
    USART_Cmd(UARTd, ENABLE);
}
