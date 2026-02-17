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


int gush_execute(t_program *cmd);
int perform_complex_execution(t_program *cmd);
int perform_simple_execution(t_program *cmd);

#endif