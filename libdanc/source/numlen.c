/*
 * ________________________________________________________________________________
 * |  File: numlen.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:24 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

size_t	numlen(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
