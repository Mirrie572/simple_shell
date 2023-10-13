#include "shell.h"

/**
 * envi - print environmental
 *
 * Return: nothing
 */

void envi(void)
{
int index = 0;

while (environ[index])
{

_puts(environ[index]);
index++;

}

}

/**
 * prompt - the main shell prompt for user to enter input
 *
 * Return: the users input
 */

char *prompt(void)
{
ssize_t input_lenght;
char *cmd = NULL;
size_t buffer_size = 0;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "shell$ ", 5);

input_lenght = getline(&cmd, &buffer_size, stdin);

if (input_lenght == -1)
{
free(cmd);
return (NULL);
}

return (cmd);

}


/**
 * split - tokenizes input from user
 *
 * @input: the command entered by the user
 *
 * Return: a string 2D array
 *
 */

char **split(char *input)
{

int token_count = 0;
char **command_tokens = NULL;
char *token = NULL;
char *input_copy = NULL;

if (!input)
return (NULL);

input_copy = _strdup(input);
token = _strtok(input_copy, CUSTOM_DELIMITERS);

if (token == NULL)
{
free(input);
free(input_copy);
return (NULL);
}

while (token)
{
token_count++;
token = _strtok(NULL, CUSTOM_DELIMITERS);
}

free(input_copy);

command_tokens = malloc(sizeof(char *) * (token_count + 1));
if (!command_tokens)
}
free(input);
return (NULL);
}

token_count = 0;
token = _strtok(input, CUSTOM_DELIMITERS);

while (token)
{
command_tokens[token_count] = _strdup(token);
token = _strtok(NULL, CUSTOM_DELIMITERS);
token_count++;
}

free(input);
command_tokens[token_count] = NULL;

return (command_tokens);
}
