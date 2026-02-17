/*
 * ________________________________________________________________________________
 * |  File: is_whitespace.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:29 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

bool	is_whitespace(char *s)
{
	int	i;
	int	len;

	len = strlen(s);
	i = 0;
	while (s[i])
	{
		if (i != len)
		{
			if (s[i] != ' ')
				return (false);
			i++;
		}
	}
	return (true);
}
