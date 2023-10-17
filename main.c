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
