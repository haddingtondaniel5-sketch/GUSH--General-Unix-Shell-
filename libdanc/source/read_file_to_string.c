/*
 * ________________________________________________________________________________
 * |  File: read_file_to_string.c
 * |  Project: source
 * |  File Created: Tuesday, 10th December 2024 07:13 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

char *read_file_to_string(const char *filename)
{
	char *out;
	FILE *f = fopen(filename, "r");
	if (!f)
	{
		save_to_error_txt("failed to open file in read_file_to_string()");
		return NULL;
	}
	fseek(f, 0, SEEK_END);
	unsigned long file_size = ftell(f);
	rewind(f);
	out = msg_malloc(sizeof(char) * (file_size + 1), "allocation for out in read_file_to_string()");
	if (!out)
		return (NULL);

	size_t bytes_read = fread(out, 1, file_size, f);
	if (bytes_read != file_size)
	{
		save_to_error_txt("failed to read entire file");
		free(out);
		fclose(f);
		return NULL;
	}
	out[bytes_read] = '\0';
	fclose(f);
	return out;
}