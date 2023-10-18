#include "shell.h"

/**
 * main - the main function for this shell
 * @argc: the number of arguements
 * @argv: pointer to all arguments
 * @envptr: pointer environmental variables
 *
 * Return: zero always
 */

int main(int argc, char **argv, char **envptr)
{

(void)argc;

start();
user_info_handler(envptr, argv);
return (EXIT_SUCCESS);

}


/**
 * prompt - main shell prompt
 * @cmd: the command to be entered
 */

void prompt(char *cmd)
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

prompt("$ ");

}
