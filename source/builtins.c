/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    builtins.c
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

#include "../include/gush.h"

void gush_exit(char **args, t_program *cmd)
{
    int code = 0;
    if (args[1])
        code = atoi(args[1]);
    else
        code = cmd->status;
    cleanup(cmd);
    exit(code);
}

int gush_cd(char **args)
{
    int error_code;

    return 0;
}

int gush_unset(char **args)
{
    int error_code;

    return 0;
}

int gush_export(char **args)
{
    int error_code;

    return 0;
}

int gush_env(char **envv)
{
    print_list_2d(envv);

    return 0;
}


