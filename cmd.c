#include "shell.h"

/**
 * cmd_handler - Check and execute built-in commands.
 * @str: Array of command tokens.
 * @estatus: the exit status pointer
 * @count: keeps tracck of the count
 * @argv: command args pointer.
 *
 * Return:  cmd was executed 1 otherwise 0
 */
int cmd_handler(char **str, int *estatus, int count, char **argv)
{
int n = 0;
char *command_name = str[0];

builtins_cmd commands[] = {
{ "env", env_cmd },
{ "exit", exit_cmd},
{ "setenv", setenv_cmd },
{ "unsetenv", unsetenv_cmd },
{ "cd", cd_cmd },
{ NULL, NULL }
};

if (str == NULL || str[0] == NULL)
return (0);

while (commands[n].ptr != NULL)
{
if (_strcmp(command_name, commands[i].cmd_name) == 0)
{
commands[n].ptr(str, estatus, count, argv);

return (1);
}

n++;

}

return (0);

}

/**
 * env_cmd - this prints all env variables
 * @str: Points at the str of arrays token.
 * @estatus: Points to the exit status
 * @count: keep track of the token count
 * @argv: command arguments.
 *
 * Return: Always returns 1.
 */

int env_cmd(char **str, int *estatus, int count, char **argv)
{
int n;
n = 0;
(void)argv; /* must be disregarded*/
(void)str; /* added for para call reasons only*/
(void)estatus;
(void)count;

while (environ[n])
{
write(STDOUT_FILENO, environ[n], _strlen(environ[n]));
write(STDOUT_FILENO, "\n", 1);
n++;
}
return (0);
}

/**
 * exit_cmd - this is the custom exit command
 * @str: a cmd token as an array of strings
 * @estatus: Pointer to the exit status after.
 * @count: keep track of the command count
 * @argv: Pointer to the command arguments.
 *
 * Return: its zero all the time
 */
int exit_cmd(char **str, int *estatus, int count, char **argv)
{
char *merror = malloc(sizeof(char) * BUFFER_SIZE);

_memset(merror, 0, sizeof(char) * BUFFER_SIZE);

if (str[1] != NULL)
{
if (_atoi(str[1]) <= 0)
{
msg_cerror(merror, argv[0],count, str[1]);
write(STDERR_FILENO, merror, _strlen(merror));
free(merror);
exit(2);
}
else
{
char *buffer;
buffer = malloc(BUFFER_SIZE);

_strcpy(buffer, str[1]);

free(estatus);
farray(str);
free(str);
free(merror);
exit(_atoi(buffer));
}
}
else
{
int placeholder = *estatus;

farray(str);
free(str);
free(merror);
free(estatus);
exit(placeholder);
}
return (0);

}

/**
 * _setenv_cmd - inizialize or modify an environment variable.
 * @str: Pointer to an array of tokens.
 * @estatus: Pointer to the exit status.
 * @tracker: keeps track of the cycle count
 * @argv: Pointer to the command arguments.
 *
 * Return: 0 on success otherwise -1.
 */
int _setenv_cmd(char **str, int *estatus, int tracker, char **argv)
{

(void) estatus;
(void) tracker;
(void) argv;

if (str[1] == NULL || str[2] == NULL || str[3] != NULL)
{
write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
return (-1);
}

if (setenv(str[1], str[2], 1) == -1)
{
write(STDERR_FILENO, "setenv: error setting envi\n", 43);
return (-1);
}

return (0);

}

/**
 * _unsetenv_command - deletees the set of environment variable.
 * @str: a string Pointer to an array of tokens.
 * @estatus: Pointer to the exit status.
 * @tracker: keeps track of the count cycle.
 * @argv: command arguemnts pointer
 *
 * Return: 0 on success otherwise -1
 */
int _unsetenv_cmd(char **str, int *estatus, int tracker, char **argv)
{
(void) estatus;
(void) tracker;
(void) argv;

if (str[1] == NULL || str[2] != NULL)
{
write(STDERR_FILENO, "Usage: deleted the  VARIABLE\n", 26);
return (-1);
}

if (unsetenv(str[1]) == -1)
{
write(STDERR_FILENO, "unsetenv: error in deleting environment variable\n", 47);
return (-1);
}
return (0);
}

