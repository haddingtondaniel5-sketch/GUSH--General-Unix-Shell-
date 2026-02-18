/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    env.c
 * Author:  Daniel Haddington
 * Created: 2026-02-19
 * 
 */

#include "../include/gush.h"

char *retrieve_env(char *var, char **envv)
{
    int i = 0;
    char *tmp;
    int var_length = strlen(var);

    while (envv[i])
    {
        if (strncmp(var, envv[i], var_length) == 0 && envv[i][var_length] == '=')
            return &envv[i][var_length + 1];
        i += 1;
    }
    return NULL;
}

char *get_program_path(char *program_name, char **envv)
{
    char *full_path;
    char **path_env_var;
    int i = 0;

    path_env_var = split(retrieve_env("PATH", envv), ':');
    if (!path_env_var) return NULL;

    while(path_env_var[i])
    {
        char *tmp = strjoin_e(3, path_env_var[i], "/", program_name);
        if (access(tmp, X_OK) == 0)
            return tmp;

        free(tmp);
        i += 1;
    }
    return NULL;

}