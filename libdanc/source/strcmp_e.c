/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    strcmp_e.c
 * Author:  Daniel Haddington
 * Created: 2026-02-18
 * 
 */

 #include "../include/libdanc.h"



int strcmp__e_internal(char *check, ...)
{
    va_list arg;
    char *tmp;

    va_start(arg, check);
    
    while((tmp = va_arg(arg, char *)))
    {
        if (strcmp(check, tmp) == 0)
        {
            va_end(arg);    
            return 1;
        }
    }
    va_end(arg);
    return 0;
}
