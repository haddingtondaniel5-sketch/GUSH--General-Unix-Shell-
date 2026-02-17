/*
 * ________________________________________________________________________________
 * |  File: bitsetter.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 03:23 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

u32 bitsetter(u32 result, ...)
{
	va_list args;
	va_start(args, result);

	u32 bit;
	while ((bit = va_arg(args, u32)) != (u32)-1) {
		result |= (1 << (bit));
	}

	va_end(args);
	return result;
}