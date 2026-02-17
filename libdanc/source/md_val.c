/*
 * ________________________________________________________________________________
 * |  File: md_val.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 08:24 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"


u32 md_val(char *_x_)
{
	u32		val;
	size_t	index;
	char	*endptr;

	val = 0;
	index = 0;
	if ((_x_[0] == '_') && (_x_[1] <= 'P' && _x_[1] >= 'A') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[1] - 64);
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else if ((_x_[0] <= 'P' && _x_[0] >= 'A') && (_x_[1] == '_') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[0] - 48);
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else
	{
		return (0);
	}
	return (val);
}