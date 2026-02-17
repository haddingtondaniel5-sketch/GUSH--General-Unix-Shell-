/*
 * ________________________________________________________________________________
 * |  File: split.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:15 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char	**split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	k = wordcnt(s, c);
	split = msg_malloc(sizeof(char *) * (k + 1), "allocation for split() failed");
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = 0;
		while (s[j] != c && s[j])
			j++;
		split[i] = strndup(s, j);
		if (!split[i])
		{
			save_to_error_txt("string allocation failed in split(), split[i]");
			for (size_t b = 0; b < i; b++)
				safe_free(split[b]);
			safe_free(split);
			return (NULL);
		}
			
			
		i++;
	}
	split[i] = 0;
	return (split);
}
