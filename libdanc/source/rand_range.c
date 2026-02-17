/*
 * ________________________________________________________________________________
 * |  File: rand_range.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 02:53 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

int rand_range(int l, int r)
{
	return ((rand() % (r - l + 1)) + l);
}