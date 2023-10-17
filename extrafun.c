#include "shell.h"
#include <stdlib.h>

/**
 * itoa - Convert an integer to a string.
 * @value: The integer value to convert.
 * @buffer: The buffer to store the resulting string.
 * @radix: The base for numerical representation (e.g., 10 for decimal).
 * @is_negative: Flag indicating if the value is negative.
 * Return: A pointer to the resulting string.
 */
char *itoa(int value, char *buffer, int radix, int is_negative)
{
int digit, right;
int n = abs(value);

int i = 0;
int left = 0;
char temp;

if (n == 0)
{
buffer[i++] = '0';
}
else
{
while (n != 0)
{
digit = n % radix;
buffer[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
n /= radix;
}
}

if (is_negative)
{
buffer[i++] = '-';
}

buffer[i] = '\0';

/* Reverse the string */
right = i - 1;

while (left < right)
{
temp = buffer[left];
buffer[left] = buffer[right];
buffer[right] = temp;
left++;
right--;
}

return (buffer);

}

/**
 * prerror - prints an error message upon failure
 * @name: name of the shell
 * @cmd_name: the cmd name
 * @i: the index of the command
 *
 * Return: nothing
 */

void prerror(char *name, char *cmd_name, int i)
{

char str_i[12];

itoa(i, str_i, 10, 0);

write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, str_i, _strlen(str_i));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd_name, _strlen(cmd_name));
write(STDERR_FILENO, ": can not be found\n", 12);

}

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
 * cerror - it Concatenate result errors
 * @buff: it stores the error results
 * @name: the program name 
 * @tracker: count and track the tokens
 * @cmd: the error command to be concatenated
 *
 * Return: nothing
 */

void msg_cerror(char *buff, const char *name, int tracker, const char *cmd)
{
int n;
int digit = 1;
const char *msg = "error: ";
int len = 0;
int count = tracker;

while (*name != '\0')
buff[len++] = *name++;
buff[len++] = ':';
buff[len++] = ' ';

while (count / 10 > 0)
{
digit++;
count /= 10;
}
for (n = 0; n < digit; n++)
{
buff[len + digit - n - 1] = '0' + (tracker % 10);
tracker /= 10;
}
len += digit;
buff[len++] = ':';
buff[len++] = ' ';

while (*msg != '\0')
buff[len++] = *msg++;

while (*cmd != '\0')
buff[len++] = *cmd++;
buff[len++] = '\n';
buff[len] = '\0';
}
