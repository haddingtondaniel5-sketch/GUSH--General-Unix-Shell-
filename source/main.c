/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    main.c
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */


#include "../include/gush.h"

void cleanup(t_program *c)
{
    safe_free(c->command_starts);
    safe_free(c->operator_list);
    safe_free(c->args);
    safe_free(c);
}

char *gush_read_line(const char *prompt, t_program *cmd) {
    char *line = NULL;
    line = readline(prompt);
    if (line == NULL)
    {
        safe_free(line);
        error_exit("Shell Exited\n", 0, cmd,  cleanup);
    }
    return line;
}

void initialise_struct(t_program *cmd)
{
    cmd->argc = 0;
    cmd->args_size = GUSH_TOK_BUFSIZE;
    cmd->args = malloc(sizeof(char *) * cmd->args_size);
    cmd->command_starts = malloc(sizeof(int) * cmd->args_size);
    for (int i = 0; i < cmd->args_size; i += 1)
        cmd->command_starts[i] = -1;
    cmd->operator_list = malloc(sizeof(char *) * cmd->args_size);
    cmd->operator_list[0] = NULL;
    cmd->args[0] = NULL;
    cmd->prompt = NULL;
}

void set_prompt(t_program *cmd)
{
    safe_free(cmd->prompt);

    __uid_t uid = getuid();
    char *symbol;
    if (uid == 0) symbol = "#"; else symbol = "$";

    cmd->username = getpwuid(uid)->pw_name;
    gethostname(cmd->hostname, HNAME_SIZE);
    getcwd(cmd->current_working_dir, CWD_SIZE);
    cmd->prompt = strjoin_e(13, B_PURPLE , cmd->username, B_WHITE, "@", B_PURPLE, cmd->hostname, WHITE, ":", B_CYAN, cmd->current_working_dir, GREEN, symbol, " ");
}

int main(int argc, char **argv, char **envv)
{
    (void)argc;
    (void)argv;

    t_program *cmd = malloc(sizeof(t_program));
    if (!cmd)
        ERROR_MEM(cmd, "struct in shell could not be allocated");
    cmd->envv_working_copy = tabdup(envv);
    initialise_struct(cmd);

    while (1) {

        set_prompt(cmd);
        char *line = gush_read_line(cmd->prompt, cmd);
        
        
        if (line && *line != '\0') // skip empty lines
        {
            add_history(line);     
            
            gush_parse_line(line, cmd);
            print_list_2d(cmd->args);
        }
        free(line);
    }
}