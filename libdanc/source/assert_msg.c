/*
 * ________________________________________________________________________________
 * |  File: assert_msg.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 03:12 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void assert_msg(int condition, const char *msg, const char *file, int line) 
{
	if (!condition) {
		fprintf(stderr, "Assertion failed: %s\nFile: %s, Line: %d\n", msg, file, line);
		exit(EXIT_FAILURE);
    }
}