#include "shell.h"

/**
 * prompt - main shell prompt
 * @cmd: the command to be entered
 */

void *prompt(char *cmd)
{

if (isatty(STDIN_FILENO))
{
write(STDIN_FILENO, cmd, 2);
fflush(stdout);
}

}

/**
 * start - this where the program starts
 * Description: does all the necessary for the  setup for the pragram to start
 */

void start(void)
{

signal(SIGINT, sighandler);

prompt("hsh$ ");

}


/**
 * split_input_line - Splits an input line into tokens
 * @env: The environment variables
 * @argv: The command-line arguments
 * @input: The input line
 * @name: The name of the executable
 * @count: The current cycle count
 * @estatus: the exit code for exiting.
 */
void split_input_line(char **env, char **argv, char *input, char *name, int count, int *exit_status)
{
char *exe_path = (char *)malloc(sizeof(char) * PATH_SIZE);
char **tokens = (char **)malloc(sizeof(char *) * TOKEN_SIZE);
char *err_msg = (char *)malloc(sizeof(char *) * TOKEN_SIZE);
int is_built_in, token_count;

_memset(name, 0, TOKEN_SIZE);
input_process(input, &token_count, name, exit_status, count, argv, tokens, &is_built_in);

if (token_count > 0 && tokens != NULL && !is_built_in)
{
exe_path = find_executable(env, tokens[0], name, exe_path);
if (exe_path)
*exit_status = execute_command(exe_path, env, tokens, argv[0]);
else
{
msg_cerror(err_msg, argv[0],
count, tokens[0]);
write(STDERR_FILENO, err_msg, _strlen(err_msg));
if (!isatty(STDIN_FILENO))

exit(127);

}
}
free(exe_path);
free_tokens(tokens);
free(tokens);
free(err_msg);
}



/**
 * user_info_handler - handle user input and the  execution
 * @env: apointer to an array string of  environment variables
 * @argv: pointer to an array string of command-line arguments
 *
 * Returns: Nothing
 */

void user_info_handler(char **env, char **argv)
{
int cycle_count = 1, in_double_quotes = 0;
char exe_name[TOKEN_SIZE], *multiline_buffer = NULL, input_char;
size_t buffer_size = BUFFER_SIZE, buffer_index = 0;
int *estatus = (int *)malloc(sizeof(int));

multiline_buffer = (char *)malloc(buffer_size);
*estatus = 0;
while (1)
{
input_char = _getline();
if (input_char == EOF)
break;
else if (input_char == '"' && in_double_quotes == 0)
in_double_quotes = 1;
else if (input_char == '"' && in_double_quotes == 1)
in_double_quotes = 0;
else if (input_char == '\n' && in_double_quotes == 0)
{
multiline_buffer[buffer_index] = '\0';
split_input_line(env, argv, multiline_buffer,
exe_name, cycle_count, estatus);
buffer_index = 0;
cycle_count++;
prompt("hsh$ ");
}
else
{
multiline_buffer[buffer_index] = input_char;
buffer_index++;
if (buffer_index >= buffer_size)
{
buffer_size *= 2;
multiline_buffer = _realloc(multiline_buffer, buffer_size);
}
}
}
free(multiline_buffer);
free(estatus);
}

/**
 * input_process- Process and execute what the user has entered.
 *
 * @input_line: The user input line to be processed.
 * @token_count: hold num tof string token 
 * @buff: A buffer to store the executed cmd.
 * @exit_status: the exit status pointer
 * @str: the string tokens
 * @tracker: counts the cycle and keep track
 * @argv: Pointer to the command arguments.
 * @b_flag: boolean used to  indicate whether the input corresponds to a built-in command.
 *
 * 
 * Return: (char **) An array of tokens.
 */

void input_process(char *input_line, int *token_count, char *buff, int *exit_status, int tracker, char **argv, char **str, int *b_flag)
{

split(input_line, str);

*token_count = count_tokens(str);
if (*token_count > 0)
_strcpy(b_flag, str[0]);

*b_flag = cmd_handler(str, estatus, tracker, argv);

}


/**
 * split - a string will be split into a line
 * @str: the string to be split.
 * @tokens: the tokens that.
 *
 * Return: An array of tokens otherwise 
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