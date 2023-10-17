#include "shell.h" 

/**
 * error_mesg - Concatenate error message components
 * @message: Buffer to store the error message
 * @name: Name of the program
 * @count: Cycle count
 * @command: Command causing the error
 *
 * Return: Nothing
 */
void error_mesg(char *message, const char *name, int count, const char *command)
{
int len = 0, f;
int cycle = count;
int digits = 1;
const char *not_f = "cd: can't cd to ";

while (*name != '\0')
message[len++] = *name++;

message[len++] = ':';
message[len++] = ' ';

while (cycle / 10 > 0)
{
digits++;
cycle /= 10;
}
for (f = 0; f < digits; f++)
{
message[len + digits - f - 1] = '0' + (count % 10);
count /= 10;
}
len += digits;

message[len++] = ':';
message[len++] = ' ';

while (*not_f != '\0')
message[len++] = *not_f++;

while (*command != '\0')
message[len++] = *command++;

message[len++] = '\n';
message[len] = '\0';
}

/**
 * cd_cmd - Custom cd prints the  current directory.
 * @tokens: Pointer to an array of tokens.
 * @exit_status: Pointer to the exit status.
 * @count: keeps track of the count.
 * @argv: Pointer to the command arguments.
 *
 * Return: always zero toherwise -1
 */

int cd_cmd(char **tokens, __attribute__((unused)) int *exit_status, int count, char **argv)
{
char *new_dir;
char current_dir[PATH_SIZE];

if (tokens[1] == NULL || tokens[2] != NULL)
{
new_dir = getenv("HOME");
if (new_dir == NULL)
getcwd(new_dir, PATH_SIZE);
}
else if (_strcmp(tokens[1], "-") == 0)
{
new_dir = getenv("OLDPWD");
if (new_dir == NULL)
getcwd(new_dir, PATH_SIZE);
}
else
new_dir = tokens[1];

if (getcwd(current_dir, PATH_SIZE) == NULL)
{

perror("getcwd");
return (-1);
}

if (chdir(new_dir) == -1)
{
char *msgerror = (char *)malloc(BUFFER_SIZE);

error_mesg(msgerror, argv[0], count, new_dir);
write(STDERR_FILENO, msgerror, _strlen(msgerror));
free(msgerror);
return (-1);
}
setenv("OLDPWD", current_dir, 1);
setenv("PWD", new_dir, 1);
if (_strcmp(tokens[1], "-") == 0)
{
write(STDOUT_FILENO, new_dir, _strlen(new_dir));
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}

/**
 * _strpbrk - Locate the first occurrence of any character in a set.
 * @str: The string to search.
 * @s_str: The set of characters to search for.
 * 
 * Return: A pointer to the first matching character,
 * or NULL if none are found.
 */

char *_strpbrk(const char *str, const char *s_str)
{
while (*str)
{
const char *m = s_str;

while (*m)
{
if (*m == *str)
{
return ((char *)str);
}
m++;
}
str++;
}
return (NULL);
}

/**
 * _strstr - Locate a substring in a string.
 * @str: The string to search in.
 * @n_str: The substring to search for.
 * 
 * Return: A pointer to the beginning of the substring, or NULL if not found.
 */
char *_strstr(const char *str, const char *n_str)
{
int n;
int m;

for (n = 0; str[n] != '\0'; n++)
{
for (m = 0; n_str[m] != '\0'; m++)
{
if (str[n + m] != n_str[m])
break;
}

if (n_str[m] == '\0')
return ((char *)&str[n]);
}
return (NULL);

}
