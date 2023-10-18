#include "shell.h"

/* betty error for the prototypes */
void tokenize_line(char **env, char **argv, char *input_line,
char *name, int tracker, int *estatus);

/**
 * tokenize_line - Splits an input line into tokens
 * @env: The environment variables
 * @argv: The command-line arguments
 * @input_line: The input line
 * @name: The name of the executable
 * @tracker: The current cycle count
 * @estatus: the exit code for exiting.
 *
 * Return: nothing
 */

void tokenize_line(char **env, char **argv,
char *input_line, char *name, int tracker, int *estatus)
{
char *msgerror = (char *)malloc(sizeof(char *) * TOKEN_SIZE);
char *execute_path = (char *)malloc(sizeof(char) * PATH_SIZE);
char **tokens = (char **)malloc(sizeof(char *) * TOKEN_SIZE);

int b_flags;
int token_count;

_memset(name, 0, TOKEN_SIZE);
input_process(input_line, &token_count, name,
estatus, tracker, argv, tokens, &b_flags);

if (token_count > 0 && tokens != NULL && !b_flags)
{
execute_path = full_path(env, tokens[0], name, execute_path);
if (execute_path)
*estatus = execute_cmd(execute_path, env, tokens, argv[0]);
else
{

msg_cerror(msgerror, argv[0], tracker, tokens[0]);
write(STDERR_FILENO, msgerror, _strlen(msgerror));
if (!isatty(STDIN_FILENO))

exit(127);

}
}
free(execute_path);
farray(tokens);
free(tokens);
free(msgerror);
}



/**
 * user_info_handler - handle user input and the  execution
 * @env: apointer to an array string of  environment variables
 * @argv: pointer to an array string of command-line arguments
 *
 * Returns: Nothing
 */
void user_info_handler(char **env, char **argv);

void user_info_handler(char **env, char **argv)
{
int count = 1;
int doqs = 0;
char name[TOKEN_SIZE];
char *mutbuf = NULL;
char c;
size_t size = BUFFER_SIZE;
size_t i = 0;
int *estatus = (int *)malloc(sizeof(int));

mutbuf = (char *)malloc(size);
*estatus = 0;
while (1)
{
c = _getline();
if (c == EOF)
break;
else if (c == '"' && doqs == 0)
doqs = 1;
else if (c == '"' && doqs == 1)
doqs = 0;
else if (c == '\n' && doqs == 0)
{
mutbuf[i] = '\0';
tokenize_line(env, argv, mutbuf, name, count, estatus);

i = 0;
count++;
prompt("$ ");
}
else
{
mutbuf[i] = c;
i++;

if (i >= size)
{
size *= 2;
mutbuf = _realloc(mutbuf, size);
}
}
}

free(mutbuf);
free(estatus);

}

/**
 * input_process- Process and execute what the user has entered.
 *
 * @input_line: The user input line to be processed.
 * @token_count: hold num tof string token
 * @buff: A buffer to store the executed cmd.
 * @estatus: the exit status pointer
 * @str: the string tokens
 * @tracker: counts the cycle and keep track
 * @argv: Pointer to the command arguments.
 * @b_flag: boolean used to  indicate
 *
 * Return: (char **) An array of tokens.
 */

void input_process(char *input_line, int *token_count,
char *buff, int *estatus, int tracker, char **argv, char **str, int *b_flag);

void input_process(char *input_line, int *token_count,
char *buff, int *estatus, int tracker, char **argv, char **str, int *b_flag)
{
split(input_line, str);

*token_count = counter(str);

if (*token_count > 0)

_strcpy(buff, str[0]);

*b_flag = cmd_handler(str, estatus, tracker, argv);

}

/**
 * split - a string will be split into a line
 * @str: the string to be split.
 * @tokens: the tokens that.
 *
 * Return: An array of tokens otherwise.
*/
char **split(char *str, char **tokens)
{

char *token;
char *r = str;

int tracker = 0;

while ((token = _strtok(r, " ")) != NULL)
{

r = NULL;

if (token[0] == '\'' || token[0] == '"')
{
char *close = _strchr(token + 1, token[0]);

if (close != NULL)
{
*close = '\0';
tokens[tracker] = _strdup(token + 1);
tracker++;

}
else
{
tokens[tracker] = _strdup(token);
tracker++;
}
}
else
{
tokens[tracker] = _strdup(token);
tracker++;
}
}
tokens[tracker] = NULL;

return (tokens);

}
