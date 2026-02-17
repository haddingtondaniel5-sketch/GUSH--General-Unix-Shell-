/*
 * ________________________________________________________________________________
 * |  File: tabdup.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:23 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char	**tabdup(char **in)
{
	size_t	i;
	char	**out;

	i = 0;
	out = msg_malloc(sizeof(char *) * (lstlen(in) + 1), "allocation for tabdup() failed");
	if (!out)
		return (NULL);
	while (in[i])
	{
		out[i] = strdup(in[i]);
		if (!out[i])
			save_to_error_txt("string allocation failed, out[i]");
		i++;
	}
	out[i] = NULL;
	return (out);
}
