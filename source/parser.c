/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    parser.c
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

#include "../include/parser.h"

void gush_parse_line(char *line, t_program *cmd) { // Thankyou Google Gemini
    int i = 0;
    int arg_idx = 0;
    bool in_s_quote = false;
    bool in_d_quote = false;

    while (line[i]) {
        // 1. Skip leading whitespace
        while (line[i] && strchr(GUSH_TOK_DELIM, line[i]) && !in_s_quote && !in_d_quote)
            i++;
        if (line[i] == '\0') break;

        // 2. CHECK SPACE: Do we need a bigger boat?
        // We use -1 to ensure there is ALWAYS room for the trailing NULL
        if (arg_idx >= cmd->args_size - 1) {
            cmd->args_size += GUSH_TOK_BUFSIZE;
            char **new_args = realloc(cmd->args, cmd->args_size * sizeof(char *));
            if (!new_args) ERROR_MEM(cmd, "Realloc failed");
            cmd->args = new_args;
        }

        // 3. Mark the start
        if (line[i] == '\'' || line[i] == '\"') {
            if (line[i] == '\'') in_s_quote = true; else in_d_quote = true;
            i++; 
        }
        cmd->args[arg_idx++] = &line[i];

        // 4. Scan until the end of this token
        while (line[i]) {
            if (in_s_quote && line[i] == '\'') {
                in_s_quote = false;
                line[i++] = '\0';
                break;
            }
            if (in_d_quote && line[i] == '\"') {
                in_d_quote = false;
                line[i++] = '\0';
                break;
            }
            if (!in_s_quote && !in_d_quote && strchr(GUSH_TOK_DELIM, line[i])) {
                line[i++] = '\0';
                break;
            }
            i++;
        }
    }
    cmd->args[arg_idx] = NULL;
    cmd->argc = arg_idx;
}
