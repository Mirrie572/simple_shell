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





}
