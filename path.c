#include "shell.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * get_envi - it gives the value of environmental variable
 * @name: name of the environmental variable
 *
 * Return: the value of the environmental variable.
 *
 */

char *get_envi(const char *name)
{

int index = 0;
char *copy, *key;
char *value, *env_value;

for (; environ[index]; index++)
{

copy = _strdup(environ[index]);
key = _strtok(copy, "=");

if (_strcmp(key, name) == 0)
{
value = _strtok(NULL, "\n");
env_value = _strdup(value);

free(copy);
return (env_value);

}
free(copy);
copy = NULL;
}
return (NULL);
}


/**
 * get_full_path - gets the full path of the command
 * @input: the command entered by user
 *
 * Return: the full path of the command
 */

char *get_full_path(char *input)
{

char *env_path;
char *cmd, *path;
int index;

for (index = 0; input[index]; index++)
{
if (input[index] == '/')
{
if (access(input, F_OK) == 0)
return (_strdup(input));
return (NULL);
}
}

env_path = get_envi("PATH");
if (!env_path)
return (NULL);

path = _strtok(env_path, ":");

while (path)
{
cmd = malloc(_strlen(path) + _strlen(input) + 2);
if (cmd)
{
_strcpy(cmd, path);
_strcat(cmd, "/");
_strcat(cmd, input);
if (access(cmd, F_OK) == 0);
{
free(env_path);
return (cmd);
}
free(cmd),cmd = NULL;
path = _strtok(NULL, ":");
}
}
free(env_path);
return (NULL);
}
