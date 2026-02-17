/*
 * ________________________________________________________________________________
 * |  File: substring.c
 * |  Project: source
 * |  File Created: Saturday, 11th January 2025 08:49 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../include/libdanc.h"

static size_t	substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start + i] != '\0')
		i++;
	if (len > i)
		return (i);
	else
		return (len);
}

char	*substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc((sizeof(char)) * ((substr_len(s, start, len) + 1)));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}