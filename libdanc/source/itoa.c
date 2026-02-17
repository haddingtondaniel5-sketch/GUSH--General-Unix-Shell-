/*
 * ________________________________________________________________________________
 * |  File: itoa.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 06:33 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char	*itoa(int n)
{
	char	*str;
	int		num;
	size_t	len;

	len = numlen(n);
	str = msg_malloc(sizeof(char) * (len + 1), "allocation for itoa() failed");
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
