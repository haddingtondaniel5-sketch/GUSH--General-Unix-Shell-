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

int check_4_operators(t_program *cmd)
{
    int i = 0;
    int op_count = 0;
    cmd->command_starts[0] = 0;

    while (cmd->args[i])
    {
        if (strcmp(cmd->args[i], "&&") == 0 ||
            strcmp(cmd->args[i], "||") == 0 ||
            strcmp(cmd->args[i], ";") == 0 ||
            strcmp(cmd->args[i], ">") == 0 ||
            strcmp(cmd->args[i], ">>") == 0 || 
            strcmp(cmd->args[i], "|") == 0      )
            {
                if (op_count >= cmd->args_size - 1)
                {
                    cmd->args_size += GUSH_TOK_BUFSIZE;
                    char **tmp_ops = realloc(cmd->operator_list, sizeof(char *) * cmd->args_size);
                    char *tmp_starts = realloc(cmd->command_starts, sizeof(int) * cmd->args_size);

                    if (!tmp_ops || !tmp_starts)
                        ERROR_MEM(cmd, "reallacation failed in check_4_operators");
                    
                    cmd->operator_list = tmp_ops;
                    cmd->command_starts = tmp_starts;
                }  //Since you now have command_starts, you can actually calculate how many arguments each sub-command has by subtracting: segment_argc = command_starts[j+1] - command_starts[j] - 1;
                cmd->operator_list[op_count] = cmd->args[i];
                cmd->args[i] = NULL; 
                cmd->command_starts[op_count + 1] = i + 1;
                op_count += 1;


            }
        i += 1;
    }
    cmd->operator_list[op_count] = NULL;

    if (op_count)
        return 1;
    else
        return 0;
}
