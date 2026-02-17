/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    executor.c
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

 #include "../include/gush.h"


int perform_complex_execution(t_program *cmd)
{
    return 1;
}

int perform_simple_execution(t_program *cmd)
{
    return 1;
}


 int gush_execute(t_program *cmd)
 {
    if (check_4_operators(cmd))
        return perform_complex_execution(cmd);
    else
        return perform_simple_execution(cmd);
 }
