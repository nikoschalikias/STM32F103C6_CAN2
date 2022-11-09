[![](https://img.shields.io/badge/organization-nikoschalikias-blue.svg)](https://github.com/nikoschalikias) 
[![](https://img.shields.io/badge/remote-STM32F103C6__CAN2-green.svg)](https://github.com/nikoschalikias/STM32F103C6_CAN2) 
[![](https://img.shields.io/badge/local-F:\prj__soft\STM32F103C6__CAN2-orange.svg)]() 


* [wiki](http://www.emboxit.net/mw/index.php?title=Project_STM32F103C6_CAN)
* [wiki secure link](https://www.emboxit.net/mw/index.php?title=Project_STM32F103C6_CAN)
* [tasks](tasks.md)

# STM32F103C6_CAN2
Firmware to test the CAN-BUS operation with [CANALL_V2]() STM32F103C8 based boards 




**Targeting:**

*  Free Tool chain
*  Use no HAL libraries
*  Initialise everything directly to register level
*  Traffic to CAN-BUS only when event happens
*  No HOST, only nodes 

*  canALL_V2 boards connected on CAN-BUS network  


**Software on:** 

  * Atollic TrueSTUDIO®/STM32 Lite, Built on Eclipse.
  * Version: 2.0.1 Lite
  * Build id: 20110128-1032
*  Send to CAN only when an input is changed
*  All Receiving boards transmit to UART
   *  CAN-BUS can be monitored on PC Terminal Emulator  


**On progress:**

   *  Use board addressing to activate outputs from other board inputs
   *  *todo:* In COMMON+ mode, if Identifier matches  CAN Rx --> OUT1...8

## Board
<p align="center">
<img
src="img/09.PNG"
width = 900
/>
</p> 

## Setup
<p align="center">
<img
src="img/02
.PNG"
width = 900
/>
</p> 



## Atolic IDE

<p align="center">
<img
src="img/01.PNG"
width = 900
/>
</p> 

## Teraterm  Serial Port Setup

<p align="center">
<img
src="img/03.PNG"
width = 400
/>
</p> 

## Teraterm Terminal Setup

<p align="center">
<img
src="img/04.PNG"
width = 400
/>
</p> 

## Teraterm responce

<p align="center">
<img
src="img/10.PNG"
width = 900
/>
</p> 



## CAN and UART signals

----
At any input change:
* change is transmitted to CAN
* Overall STATUS of the board is transmitted to UART
Osilloscope:
* Blue Channel is CAN-BUS
* Purple Channel is UART-TX

<p align="center">
<img
src="img/06.PNG"
width = 600
/>
</p>

----


## Custom ST-Link and UART adapter

connects:

* ST-LINK to board
* UART to RS232 level translator board and then to PC serial port


<p align="center">
<img
src="img/08.PNG"
width = 600
/>
</p> 
