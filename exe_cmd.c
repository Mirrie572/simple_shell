#include "shell.h"

/**
 * exec_custom_cmd - Execute a custom command
 * with error handling.
 * @cmd: The command provided by the user.
 * @args: The argument vector from the main program.
 * @index: The index of the executed command.
 *
 * Return: The exit status of cmd that is 0 on success.
 */

int exec_custom_cmd(char **cmd, char **args, int index)
{
    int exit_status;
    pid_t child_pid;
    char *full_path;

    full_path = get_full_path(cmd[0]);

    if (!full_path)
    {
        prerror(args[0], cmd[0], index);
        free_array(cmd);
        return 127;
    }

    child_pid = fork();

    if (child_pid == 0)
    {
        if (execve(full_path, cmd, environ) == -1)
        {
            free(full_path);
            free_array(cmd);
        }
    }
    else
    {
        waitpid(child_pid, &exit_status, 0);
        free(full_path);
        free_array(cmd);
    }

    return WEXITSTATUS(exit_status);
}
