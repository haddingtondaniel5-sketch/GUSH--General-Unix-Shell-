/*
 * ________________________________________________________________________________
 * |  File: safe_free.c
 * |  Project: source
 * |  File Created: Wednesday, 11th December 2024 07:05 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void safe_free(void *tofree)
{
	if (tofree)
		free(tofree);
}

void	safe_free_2d_void(void **f)
{
	if (f)
	{
		size_t i = 0;
		while ((f)[i])
		{
			if (f[i])
				free((f)[i]);
			f[i] = NULL;
			i += 1;
		}
		free(f);
		f = NULL;
	}
}

void	safe_free_2d_char(char **f)
{
	if (f)
	{
		size_t	i = 0;
		while (f[i])
		{
			if (f[i])
				free(f[i]);
			f[i] = NULL;
			i += 1;		
		}
		free(f);
		f = NULL;
	}
}

void	safe_free_2d_int(int **f)
{
	if (f)
	{
		size_t	i = 0;
		while (f[i])
		{
			if (f[i])
				free(f[i]);
			f[i] = NULL;
			i += 1;		
		}
		free(f);
		f = NULL;
	}
}