/*********************************************************************
 *
 * UART support - defines pins, ports for UARTx and UARTd
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 *********************************************************************
 * FileName:    uart.h
 * Depends:
 * Processor:   STM32F100RBT6B
 *
 * Author               Date       Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Kubik                16.11.2010 Initial code
 ********************************************************************/

#ifndef _UART_H_
#define _UART_H_

//
// UARTx is used by printf
// UARTd is used by debug output (redirected stderr)
//

#define UARTx USART1
//#define UARTd USART2
#define UARTd USART1

void InitializeUarts(void);

#endif
