/*
 * ________________________________________________________________________________
 * |  File: msg_malloc.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 02:19 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void *msg_malloc(size_t size, char *mess) 
{
	void *ptr = malloc(size);
	if (!ptr) {
		save_to_error_txt(mess);
        return NULL;
    }
    return ptr;
}