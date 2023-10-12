#include "shell.h"

/**
 * main - the main function for this shell
 * @argc: the number of arguements
 * @argv: arguments
 * 
 * Return: zero always
 */

int main(int argc, char **argv)
{
(void)argc; /* ignore parameter not used*/
int count = 0;
int estatus = 0;
char **cmd = NULL;
char *line = NULL;

while(1)
{
line = prompt();

if (line == NULL) 
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1)
return (estatus);
}

count++;
cmd = tokenize(line);

if (!cmd)
continue;

if (_strcmp(cmd[0], "exit") == 0)
{
free_array(cmd);
exit(estatu);
}

if (_strcmp(cmd[0], "env") == 0)
{
envi();
free_array(cmd);
continue;
}

estatus = execute_cmd(cmd, argv, count);
}
return (0);
}
