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
ssize_t line_lenght;
size_t buffer_size = 0;
char cmd = NULL;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "shell$ ", 5);
line_length = _getline(&cmd, &buffer_size, 0);
if (line_length == -1)
{
free(cmd);
return (NULL);
}
return (cmd);
}


/**
 * tokenizer - Tokenize an input line.
 * @input: The input line to be tokenized.
 * Return: An array of tokens.
 */

char **tokenizer(char *input)
{
int token_count = 0;
char *token = NULL;
char *input_copy = NULL;
char **tokens = NULL;

if (!input)
return (NULL);

input_copy = _strdup(input);

/* Tokenize the input using the custom delimiters */
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

/* Allocate memory for the token array */
tokens = malloc(sizeof(char *) * (token_count + 1));

if (!tokens)
{
free(input);
return (NULL);
}
token_count = 0;
token = _strtok(input, CUSTOM_DELIMITERS);
while (token)
{
tokens[token_count] = _strdup(token);
token = _strtok(NULL, CUSTOM_DELIMITERS);
token_count++;
}
free(input);
tokens[token_count] = NULL;

return (tokens);
}
