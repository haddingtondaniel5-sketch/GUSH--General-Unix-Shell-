/*
 * ________________________________________________________________________________
 * |  File: write_string_to_file.c
 * |  Project: source
 * |  File Created: Tuesday, 10th December 2024 07:32 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void write_string_to_file(const char *filename, const char *content)
{
	FILE *f = fopen(filename, "w");
	if (!f)
	{
		save_to_error_txt("opening of file in write_string_to_file() failed");
		return ;
	}
	size_t len = strlen(content);
	size_t bytes_written = fwrite(content, sizeof(char), len, f);
	if (bytes_written != len)
	{
		save_to_error_txt("error writing file in its entirety; write_string_to_file()");
		return ;
	}
}
