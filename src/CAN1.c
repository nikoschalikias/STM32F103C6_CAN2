// NX: Updated 2011.03.17
// NX: Updated 2011.03.30

/*
 * testCAN1.c
 *
 *  Created on: 16 Öåâ 2010
 *      Author: ÔÇÁÍÏÓ
 */

#include "main.h"
#include "CAN1.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"

#ifdef CAN1_H_
                                  // STM32 CAN adaption layer
/*----------------------------------------------------------------------------
  initialize CAN interface
 *----------------------------------------------------------------------------*/

	CAN_InitTypeDef CAN1_InitStruct;
	CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	CanTxMsg TxMessage;
//	CanRxMsg RxMessage;
	uint32_t i = 0;
	uint8_t TransmitMailbox = 0;
	uint32_t tmp = 0x00;								// ???

//*******************************************************************************************************************************
void CAN1_setup (void) {

	//  enable clock for Alternate Function & for GPIO A
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_AFIOEN, ENABLE);
    //GPIO_PinRemapConfig(GPIO_Remap1_CAN1, ENABLE);
	// nx: GPIO_PinRemapConfig(GPIO_CAN1_onPA11_12, ENABLE);

	/* CAN register init */
	CAN_StructInit(&CAN1_InitStruct);
	CAN_DeInit(CAN1);									// Reset CAN1

	/* CAN cell init */
	CAN1_InitStruct.CAN_TTCM=DISABLE;
	CAN1_InitStruct.CAN_ABOM=DISABLE;
	CAN1_InitStruct.CAN_AWUM=DISABLE;
	CAN1_InitStruct.CAN_NART=ENABLE;	// NX: if NART is 0 then auto retransmits. Has to be 1(=ENABLE) to transmit once
	CAN1_InitStruct.CAN_RFLM=DISABLE;
	CAN1_InitStruct.CAN_TXFP=DISABLE;
	CAN1_InitStruct.CAN_Mode=CAN_Mode_Normal;		//NX:
	CAN1_InitStruct.CAN_SJW=CAN_SJW_1tq;
	CAN1_InitStruct.CAN_BS1=CAN_BS1_5tq;
	CAN1_InitStruct.CAN_BS2=CAN_BS2_2tq;			//NX: I changed to 2 from 3 to have total 8us in OSC seems correct 8us-->125KHz
	CAN1_InitStruct.CAN_Prescaler = 35;				// 125Kbps
	CAN_Init(CAN1, &CAN1_InitStruct);				// <---------- Write the Register

	/*	Initialize the CAN_Prescaler member
								  1
		  	BaudRate	= ------------------					= 1/8us = 125KHz
							NominalBitTime

		    NominalBitTime = 1 x tq + tBS1 + tBS2				= 1us + 5usec +2usec = 8us
		    with:
				tBS1 = tq x (TS1[3:0] + 1),						= 5usec
				tBS2 = tq x (TS2[2:0] + 1),						= 3usec
				tq = (BRP[9:0] + 1) x tPCLK                    	= 27.77777nsec x 36 = 1usec
				tPCLK = time period of the APB1 clock, 36MHz   	= 27.77777nsec
				BRP[9:0], TS1[3:0] and TS2[2:0] are defined in the CAN_BTR Register.
				where tq refers to the Time quantum
	*/


	/* CAN filter init *********************************************************************************************************/
//	CAN_FilterInitStructure.CAN_FilterNumber=0;
	CAN_FilterInitStructure.CAN_FilterNumber=1;
	CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;
	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;
	CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;
	CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
//	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=0;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;
	CAN_FilterInit(&CAN_FilterInitStructure);

}

/******************************************************************************************************************************
* @brief  NX: Prepare the Receive structure with the "default" values, Update the receive structure from FIFO
* @param  NX: None
* @retval NX: None
*/
void CanRx(void) {
								// NX: Prepare the Receive structure with the "default" values
								// NX: RxMessage = pointer to a structure receive message which  contains CAN Id, CAN DLC,CAN datas,FMI
								// NX: CAN receive FIFO mailbox identifier register (CAN_RIxR) (x=0..1)
	RxMessage.StdId=0x00;		// NX: Bits 31:21 STID[10:0]/EXID[28:18]: The standard identifier or the MSBs of the extended identifier
								// NX: (depending on the IDE bit value).
	RxMessage.IDE=CAN_ID_STD;	// NX: IDE=CAN_RIxR[bit2]: Identifier extension:identifier type of message in the mailbox
								// NX: 0: Standard, 1: Extended
	RxMessage.DLC=0;			// NX: DLC=CAN_TDTxR[3:0]:
								// NX: Data Length Code No# of bytes data frame contains.
								// NX: A message can contain from 0 to 8 data bytes, depending on the value in the DLC field
	RxMessage.Data[0]=0x00;		// NX: CAN receive FIFO 0 register (CAN_RF0R)
	RxMessage.Data[1]=0x00;		// NX: CAN receive FIFO 1 register (CAN_RF1R)

	CAN_Receive(CAN1, CAN_FIFO0, &RxMessage); // NX: Update the receive structure from FIFO
}

int CanRxValid(int i, int l) {
	// NX: Check for valid message
	if (RxMessage.StdId != i) {
		return FAILED;
	}
	if (RxMessage.IDE != CAN_ID_STD) {
		return FAILED;
	}
	if (RxMessage.DLC != l) {
		return FAILED;
	}
//	if (RxMessage.Data[0]  != d0) {
//		return FAILED;
//	}
//	if (RxMessage.Data[1]  != d1) {
//		return FAILED;
//	}
//	if (RxMessage.Data[2]  != d2) {
//		return FAILED;
//	}
//	if (RxMessage.Data[3]  != d3) {
//		return FAILED;
//	}
	return PASSED; /* Test Passed */
}

//*******************************************************************************************************************************

void CanTx(int i,int l,int d0,int d1, int d2,int d3) {		// NX: Identifier=0x11, Identifier-Type=Standard, Message-size=2bytes, Data[0]=0xCA, Data[1]=0xFE
	uint8_t TransmitMailbox = 0;
	TxMessage.StdId=i;
	TxMessage.RTR=CAN_RTR_DATA;
	TxMessage.IDE=CAN_ID_STD;
	TxMessage.DLC=l;
	TxMessage.Data[0]=d0;
	TxMessage.Data[1]=d1;
	TxMessage.Data[2]=d2;
	TxMessage.Data[3]=d3;
	TransmitMailbox=CAN_Transmit(CAN1, &TxMessage);									// NX: Transmit the Message
}

void CanTxWait(void){
	uint32_t i = 0;
	while ((CAN_TransmitStatus(CAN1, TransmitMailbox) != CANTXOK)				// NX: Wait Transmission to complete
			&& (i != 0xFF))
	{
		i++;
	}

	i = 0;
	while ((CAN_MessagePending(CAN1, CAN_FIFO0) < 1) 							// NX: Wait TX FIFO to empty
			&& (i != 0xFF))
	{
		i++;
	}
}

#endif
