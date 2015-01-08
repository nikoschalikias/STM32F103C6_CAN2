/*********************************************************************
 *
 * Basic debug support, inspired by Tiano
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 *********************************************************************
 * FileName:    debug.h
 * Depends:
 * Processor:   STM32F100RBT6B
 *
 * Author               Date       Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Kubik                14.11.2010 Initial code
 ********************************************************************/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef STM32_DEBUG

#include <stdarg.h>

  void DebugPrint(char *format, ...);

  #define DEBUG(arg)        DebugPrint arg
  #define DEBUG_CODE(code)  code

#else

  #define DEBUG(arg)
  #define DEBUG_CODE(code)

#endif

#endif
