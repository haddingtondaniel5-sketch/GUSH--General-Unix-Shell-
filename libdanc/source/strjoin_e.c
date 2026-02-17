/*
 * ________________________________________________________________________________
 * |  File: strjoin_e.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 06:11 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

static void	*malloc_strlen_n(size_t c, va_list arg)
{
	size_t	size;
	va_list	arg_copy;
	char	*out;

	va_copy(arg_copy, arg);
	size = 0;
	while (c)
	{
		size += strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	out = msg_malloc(sizeof(char) * (size + 1), "allocation for strjoin_e failed");
	return (out);
}

char	*strjoin_e(size_t c, ...)
{
	va_list	arg;
	char	*dcse2;
	char	*tmp;
	size_t	i;
	size_t	j;

	va_start(arg, c);
	dcse2 = malloc_strlen_n(c, arg);
	j = 0;
	if (!dcse2)
	{
		va_end(arg);
		free(dcse2);
		return (NULL);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
			dcse2[j++] = tmp[i++];
		c--;
	}
	dcse2[j] = '\0';
	va_end(arg);
	return (dcse2);
}
