/*
 * ________________________________________________________________________________
 * |  File: tabcpy.c
 * |  Project: source
 * |  File Created: Friday, 24th January 2025 12:53 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

int tabcpy(char **dest, char **src)
{
    int i = 0;

    // Check for null pointers
    if (!dest || !src)
        return -1; // Return an error code if dest or src is NULL

    // Copy each string from src to dest
    while (src[i])
    {
        dest[i] = strdup(src[i]); // Duplicate the string to avoid modifying src
        if (!dest[i])
            return -1; // Handle memory allocation failure
        i++;
    }

    // Null-terminate the destination array
    dest[i] = NULL;

    return i; // Return the number of elements copied
}