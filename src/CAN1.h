/*
 * testCAN1.h
 *
 *  Purpose   : CAN interface for STM32
 *  Created on: 16 ÷Â‚ 2010
 *      Author: ‘«¡Õœ”
 */

#ifndef CAN1_H_
#define CAN1_H_

#define STANDARD_FORMAT  0
#define EXTENDED_FORMAT  1

#define DATA_FRAME       0
#define REMOTE_FRAME     1

#include "stm32f10x.h"

	extern __IO unsigned long ret;
	extern 	CanRxMsg RxMessage;

/*
typedef struct  {
  unsigned int   id;                 // 29 bit identifier
  unsigned char  data[8];            // Data field
  unsigned char  len;                // Length of data field in bytes
  unsigned char  format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
  unsigned char  type;               // 0 - DATA FRAME, 1 - REMOTE FRAME
} CAN_msg;
*/
//	void CAN1_setup (FunctionalState CAN1_IRQ);
	void CAN1_setup ();
	void CanTx(int i,int l,int d0,int d1, int d2,int d3);
	void CanTxWait(void);
/*
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;
volatile TestStatus TestRx;
*/
TestStatus CAN_Polling(void);
TestStatus CAN_Interrupt(void);


#endif /* CAN1_H_ */


