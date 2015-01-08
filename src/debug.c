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
 * FileName:    debug.c
 * Depends:
 * Processor:   STM32F100RBT6B
 *
 * Author               Date       Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Kubik                14.11.2010 Initial code
 * Kubik                15.11.2010 Redirected debug prints to stderr
 ********************************************************************/

#include <stdio.h>
#include <sys/unistd.h>
#include "debug.h"

DEBUG_CODE (

void DebugPrint (char *format, ...) {
    va_list ap;

    va_start(ap, format);
    vdiprintf(STDERR_FILENO, format, ap);
    va_end(ap);
}

)
