/*
 * Project: Gush (General Unix Shell)
 * Folder:  include
 * File:    executor.h
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "gush.h"

int gush_execute(t_program *cmd);
int perform_complex_execution(char **args, t_program *cmd);
int perform_simple_execution(char **args, t_program *cmd);

#endif