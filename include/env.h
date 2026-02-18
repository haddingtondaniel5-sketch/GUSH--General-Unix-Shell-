/*
 * Project: Gush (General Unix Shell)
 * Folder:  include
 * File:    env.h
 * Author:  Daniel Haddington
 * Created: 2026-02-19
 * 
 */

#ifndef ENV_H
#define ENV_H
#include "gush.h"

char *retrieve_env(char *var, char **envv);
char *get_program_path(char *program_name, char **envv);

#endif