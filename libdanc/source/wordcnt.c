/*
 * ________________________________________________________________________________
 * |  File: wordcnt.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:25 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

size_t	wordcnt(char const *s, char c)
{
	size_t	word_count;
	size_t	trigger;

	trigger = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			word_count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (word_count);
}
