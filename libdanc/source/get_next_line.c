/*
 * ________________________________________________________________________________
 * |  File: get_next_line.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 04:00 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char *get_next_line(int fd)
{
	int i;
	char *line;
	int buffer_mult = 1;
	line = msg_malloc(BUFFER_SIZE, "allocation for get_next_line() failed");
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		if (i == MAX_LINE_LENGTH)
		{
			save_to_error_txt("MAX_LINE_LENGTH exceeded!");
			safe_free(line);
			return NULL;
		}
			
		if (i == BUFFER_SIZE * buffer_mult)
		{
			buffer_mult += 1;
			line = realloc(line, BUFFER_SIZE * buffer_mult);
			if (!line)
			{
				save_to_error_txt("reallocation failed, get_next_line[i]");
				return NULL;
			}
		}
		int byte_read = read(fd, &line[i], 1);
		if (byte_read == -1)
		{
			free(line);
			return NULL;
		}
		else if (byte_read == 0)
		{
			line[i] = '\0';
			if (line[0] == '\0')
				return NULL;
			return line;
		} 
		if (line[i] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = '\0';
			return line;
		}
		i += 1;	
	}
}