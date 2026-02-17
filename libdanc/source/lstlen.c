/*
 * ________________________________________________________________________________
 * |  File: lstlen.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:15 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

size_t	lstlen(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}
