/*
 * ________________________________________________________________________________
 * |  File: is_md_val.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 08:23 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

bool	is_md_val(char *_x_)
{
	if ((_x_[0] == '_') && (_x_[1] <= 'P' && _x_[1] >= 'A') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		return (true);
	}
	else if ((_x_[0] <= 'P' && _x_[0] >= 'A') && (_x_[1] == '_') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		return(true);
	}
	return (false);
}