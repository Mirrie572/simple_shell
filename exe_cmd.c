#include "shell.h"

/**
 * execute_cmd - the cmd ti be executed with its arguments.
 * @path: The full path to the executable.
 * @ptr: its a pointer to the environment variables.
 * @str: the command and its arguments as an array of string
 * @name: shell program name
 *
 * Return: the exit status or an error.
 */
int execute_cmd(char *path, char **ptr, char **str, char *name)
{
pid_t child_pid;
int estatus;    

child_pid = fork();
if (child_pid == -1)
{
perror("error");
exit(errno);
}
else if (child_pid == 0)
{
child_pid = getpid();
/* this is the parent  Child process */
if (execve(path, str, ptr) == -1)
{
perror(name);
_exit(errno);
}
}
else
{
/* this is the Parent process */
waitpid(child_pid, &estatus, WCONTINUED);
if (WIFEXITED(estatus))
{
return (WEXITSTATUS(estatus));
}
else
return (errno);
}
return (0);
}
