/*
 * ________________________________________________________________________________
 * |  File: count_tokens.c
 * |  Project: source
 * |  File Created: Saturday, 11th January 2025 10:06 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

int count_tokens(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return i;
}