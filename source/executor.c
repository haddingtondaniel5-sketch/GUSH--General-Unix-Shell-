/*
 * Project: Gush (General Unix Shell)
 * Folder:  source
 * File:    executor.c
 * Author:  Daniel Haddington
 * Created: 2026-02-14
 * 
 */

 #include "../include/gush.h"


int perform_complex_execution(char **args, t_program *cmd)
{
    int status = 0;
    return status;
}


int is_builtin(char *argument_one)
{
    if (strcmp_e(argument_one, "cd", "exit", "unset", "export", "env"))
        return 1;
}

int execute_builtin(char **args, t_program *cmd)
{
    if (strcmp(args[0], "cd") == 0)
        return gush_cd(args);
    if (strcmp(args[0], "exit") == 0)
        gush_exit(args, cmd);
    if (strcmp(args[0], "unset") == 0)
        return gush_unset(args);
    if (strcmp(args[0], "export") == 0)
        return gush_export(args);
    if (strcmp(args[0], "env") == 0)
        return gush_env(cmd->envv_working_copy);
}



int perform_simple_execution(char **args, t_program *cmd) 
{
    if (is_builtin(args[0]))
        return execute_builtin(args, cmd); // check for builtins.

    // fork and execute
    __pid_t pid = fork();

    if (pid == 0) {
        char *program_path = get_program_path(args[0], cmd->envv_working_copy);
        if (!program_path) {perror("Command not found"); exit(127);}
        if (execve(program_path, args, cmd->envv_working_copy) == -1)
        {
            free(program_path);
            perror("program failed to run");
            exit(EXIT_FAILURE);
        }
    } 
    else if (pid < 0)
    {
        perror("process fork failed");
        return 1;
    } 
    else 
    {
        int status;
        waitpid(pid, &status, WUNTRACED);
        if WIFEXITED(status)
            return WEXITSTATUS(status);
        if (WIFSIGNALED(status))
            return 128 + WTERMSIG(status);
        return 1;
    }
    return 0;
}


 int gush_execute(t_program *cmd)
 {
    if (check_4_operators(cmd))
        return perform_complex_execution(cmd->args, cmd);
    else
        return perform_simple_execution(cmd->args, cmd);
 }
