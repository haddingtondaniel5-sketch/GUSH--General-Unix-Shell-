/*
 * ________________________________________________________________________________
 * |  File: save_to_error_txt.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 05:29 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void save_to_error_txt(char *mess)
{
	FILE *err = fopen("error.txt", "a");
	fprintf(err, "%s\n", mess);
	fprintf(stderr, "%s\n", mess);
	fclose(err);
}