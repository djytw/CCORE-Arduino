// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// File name    : includes.h
// Version      : V0.1
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "iomacros.h"

void delay_tick(volatile UINT32 val);

extern u32 sysclk,ipsclk,efmclk;
#endif /* __INCLUDES_H__ */
