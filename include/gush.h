/*
 * Project: Gush (General Unix Shell)
 * Folder:  include
 * File:    gush.h
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

#ifndef GUSH_H
#define GUSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pwd.h>

# include "../libdanc/include/libdanc.h"
#include "parser.h"

#define GUSH_TOK_BUFSIZE 64
#define GUSH_TOK_DELIM " \t\r\n\a"

/* Readline non-printing markers */
#define RL_S "\001"
#define RL_E "\002"

/* Regular Text Colours */
#define BLACK   RL_S "\033[0;30m" RL_E
#define RED     RL_S "\033[0;31m" RL_E
#define GREEN   RL_S "\033[0;32m" RL_E
#define YELLOW  RL_S "\033[0;33m" RL_E
#define BLUE    RL_S "\033[0;34m" RL_E
#define PURPLE  RL_S "\033[0;35m" RL_E
#define CYAN    RL_S "\033[0;36m" RL_E
#define WHITE   RL_S "\033[0;37m" RL_E

/* Bold Text Colours */
#define B_BLACK   RL_S "\033[1;30m" RL_E
#define B_RED     RL_S "\033[1;31m" RL_E
#define B_GREEN   RL_S "\033[1;32m" RL_E
#define B_YELLOW  RL_S "\033[1;33m" RL_E
#define B_BLUE    RL_S "\033[1;34m" RL_E
#define B_PURPLE  RL_S "\033[1;35m" RL_E
#define B_CYAN    RL_S "\033[1;36m" RL_E
#define B_WHITE   RL_S "\033[1;37m" RL_E

/* Text Reset - ALWAYS use this at the end of your prompt! */
#define RESET   RL_S "\033[0m" RL_E

#define BOLD    RL_S "\033[1m"  RL_E

#define CWD_SIZE 1024
#define HNAME_SIZE 64

typedef struct s_program {
    char **args;    // Array of strings
    char current_working_dir[CWD_SIZE];
    char hostname[HNAME_SIZE];
    char *username;
    char *prompt;
    int argc;       // Number of arguments
    int args_size;

} t_program;


char *gush_read_line(const char *prompt, t_program *cmd);

int gush_execute(t_program *cmd);
void gush_free_command(t_program *cmd);


#endif