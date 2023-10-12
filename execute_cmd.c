#include "shell.h"

/**
 * execute_cmd - execute cmd with arguements
 * @full-path: points to the full path of the cmd
 * @envi: pointer of the environmental variables
 * @str: an array of command and its arguements
 * @count: keep track of number of teoken
 * @name: the name of the program running
 *
 * Return: exit or an error
 */

int execute_cmd(char *full_path, char **envi, char **str, int count, char *name)
{
pid_t child_pid;
int i, status;

child_pid = fork();

if (child_pid == -1)
{

perror("fork error")
exit(errno);
}

else if  (child_pid == 0)
{
child_pid = getpid();

if (execve(full_path, str, env) == 1)
{
perror(name);
_exit(errno);
}


}
}





}
