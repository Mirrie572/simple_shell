#include "shell.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _getenv - get the value of an environment variable.
 * @var: The name of the environment variable.
 *
 * Return: env var pointer otherwise NULL.
 */

char *_getenv(const char *var)
{
int b;

if (var == NULL || environ == NULL)
return (NULL);

for (b = 0; environ[b] != NULL; b++)
{
char *env_var = environ[b];
int c = 0;

while (var[c] != '\0' && env_var[c] == var[c])
c++;

if (var[c] == '\0' && env_var[c] == '=')
return (env_var + c + 1);

}
	return (NULL);
}

/**
 * full_path - gets the full path of the cmd
 * @envvar: the environment variables.
 * @name: te name of the executable file.
 * @f_path: this a buffer to stole the full path of executable file.
 * @e_found: store the executable found.
 *
 * Return: the path else NULL.
 */
char *full_path(char **envvar, char *name, char *f_path, char *e_found);

char *full_path(char **envvar, char *name, char *f_path, char *e_found)
{
struct stat file_stat;
char *copy;
char *path_var;
char *component;
char candidate[PATH_SIZE];

path_var = _pathv(envvar);

if (stat(name, &file_stat) == 0 && _strchr(name, '/'))
{
_strcpy(e_found, name);
return (e_found);
}
else if (path_var != NULL)
{
copy = _strdup(path_var);
component = _strtok(copy, ":");

while (component != NULL)
{
_strcpy(candidate, component);
_strcat(candidate, "/");
_strcat(candidate, f_path);

if (stat(candidate, &file_stat) == 0)
{
_strcpy(e_found, candidate);
free(copy);
return (e_found);
}

component = _strtok(NULL, ":");

}

}
free(e_found);
free(copy);

return (NULL);

}
/**
 * _pathv - Get the value of the PATH environment variable.
 * @var: name of the environmental variable
 *
 * Return: the value of the envi variable otherwise NULL.
 */

char *_pathv(char **var)
{

int index;
index = 0;

while (var[index] != NULL)
{
char *value = var[index];

if (_strstr(value, "PATH=") == value)

return (value + 5);
index++;
}
return (NULL);
}
