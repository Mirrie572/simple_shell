#include "shell.h"
#include <stdlib.h>

/**
 * count_digits - Count the number of digits in an integer.
 * @value: The integer value.
 *
 * Return: The count of digits in the integer.
 *
 */

int count_digits(int value)
{
int digit_count = 0;
int num;
num = value;

for (; num > 9 || num < -9; digit_count++)
{
num /= 10;
}

return (digit_count);

}

/**
 * counter- it counts the number of tokens in an array.
 * @str: The array of tokens to be counted
 *
 * Return: the number of tokens in the string array.
*/

int counter(char **str)
{
int tracker = 0;

while (str[tracker] != NULL)
tracker++;

return (tracker);

}

/**
 * msg_cerror - it Concatenate result errors
 * @errmsg: it stores the error results
 * @name: the program name
 * @count: count and track the tokens
 * @command: the error command to be concatenated
 *
 * Return: nothing
 */

void msg_cerror(char *errmsg, const char *name, int count, const char *command)
{
int len = 0;
const char *none = ": not found\n";
int h;

int tracker = count;
int digit = 1;

while (*name != '\0')
errmsg[len++] = *name++;

errmsg[len++] = ':';
errmsg[len++] = ' ';

while (tracker / 10 > 0)
{
digit++;
tracker /= 10;
}
for (h = 0; h < digit; h++)
{
errmsg[len + digit - h - 1] = '0' + (count % 10);
count /= 10;
}

len += digit;

errmsg[len++] = ':';
errmsg[len++] = ' ';

while (*command != '\0')
errmsg[len++] = *command++;

while (*none != '\0')
errmsg[len++] = *none++;

errmsg[len] = '\0';

}
