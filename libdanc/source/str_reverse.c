/*
 * ________________________________________________________________________________
 * |  File: str_reverse.c
 * |  Project: source
 * |  File Created: Tuesday, 10th December 2024 12:25 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char *str_reverse(char *in)
{
	char *out;
	size_t len = strlen(in);
	out = msg_malloc(sizeof(char) * (len + 1), "allocation for str_reverse failed");
	if (!out)
		return (NULL);
	size_t i = 0;
	
	while (len > 0)
	{
		out[i++] = in[--len]; 
	}
	out[i] = '\0';
	return (out);
}