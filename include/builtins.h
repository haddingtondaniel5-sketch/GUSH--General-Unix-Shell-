/*
 * Project: Gush (General Unix Shell)
 * Folder:  include
 * File:    builtins.h
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

#ifndef BUILTINS_H
#define BUILTINS_H
#include "gush.h"

void gush_exit(char **args, t_program *cmd);
int gush_cd(char **args);
int gush_unset(char **args);
int gush_export(char **args);
int gush_env(char **envv);


#endif