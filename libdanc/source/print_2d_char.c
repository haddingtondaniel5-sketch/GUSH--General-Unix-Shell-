/*
 * ________________________________________________________________________________
 * |  File: print_2d_char.c
 * |  Project: source
 * |  File Created: Wednesday, 11th December 2024 07:39 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void print_2d_char(char **p)
{
	if (p)
	{
		size_t i = 0;
		while (p[i])
		{
			printf("%s", p[i]);
			i += 1;
		}		
	}
}

void	print_list_2d(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		printf("%s\n", list[i]);
		i++;
	}
}