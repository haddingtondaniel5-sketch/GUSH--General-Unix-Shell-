/*
 * ________________________________________________________________________________
 * |  File: get_file_2d.c
 * |  Project: source
 * |  File Created: Friday, 13th December 2024 10:17 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char **get_file_2d(int fd)
{
	char **file_array;
	size_t file_len = filelen_2d(fd);
	size_t i = 0;
	file_array = msg_malloc(sizeof(char *) * (file_len + 1), "get_file_2d() allocation");
	if (!file_array)
		return(NULL);
	while (i < file_len)
	{
		file_array[i] = get_next_line(fd);
		if (!file_array[i])
		{
			while (i > 0)
			free(file_array[--i]);
			free(file_array);
			return (NULL);
		}
		i++;
	}
	file_array[i] = NULL;
	return(file_array);
}