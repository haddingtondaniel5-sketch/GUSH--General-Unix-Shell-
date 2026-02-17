/*
 * Project: Gush (General Unix Shell)
 * Folder:  include
 * File:    parser.h
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

#ifndef PARSER_H
#define PARSER_H
#include "gush.h"

void gush_parse_line(char *line, t_program *cmd);

#endif