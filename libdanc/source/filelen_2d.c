/*
 * ________________________________________________________________________________
 * |  File: filelen_2d.c
 * |  Project: source
 * |  File Created: Friday, 13th December 2024 10:12 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

size_t filelen_2d(int fd)
{
	size_t	len;
	char	*line;

	len = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		safe_free(line);
		len++;
	}
	lseek(fd, 0, SEEK_SET);
	return (len);
}