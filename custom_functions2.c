#include "shell.h"

/**
 * _strcat - its strcat replica which concatenate two strings
 * @ori:  the original string to be appended
 * @trg: target destination of the string
 *
 * Return: a pointer of the appended string
 */

char *_strcat(char *trg, char *ori)
{

char *ptr;
ptr = trg;

while (*trg)
trg++;

while (*ori)

*trg++ = *ori++;

*trg = '\0';

return (ptr);

}

/**
 * _strdup - replica of strdup which duplicates a string
 * @s: the string to be duplicaated
 *
 * Return: a pointer to the duplicated string
 */

char *_strdup(const char *s)
{

char *ptr; /* to store the results */
int len;

if (s == NULL)
return (NULL);

len = _strlen(s);

ptr = (char *)malloc(len + 1);

if (ptr == NULL)
return(NULL);
_strcpy(ptr, s);

return (ptr);

}


/**
 * _atoi - atoi replica which convert string to integer
 * @str: the string to be converted
 *
 * Return: 0 if no convertion else the interger
 */

char _atoi(const char *str)
{

unsigned int num;
int result, i;
int negative = 1, flag = 0;

for (i = 0; str[i] != '\0' && flag != 2; i++)
{
if (str[i] == '-')
negative *= -1;
if (str[i] >= '0' && str[i] <= '9')

{
flag = 1;
num *= 10;
num += (str[i] - '0');
}

else if (flag == 1)
flag = 2;
}

if (negative == -1)
result = -num;
else
result = num;

return (result);
}

/**
 * _puts - prints a string and a new line
 * @s: pointer to the string to be printed
 *
 * Return: nothing
 */

void _puts(const char *s)
{
int index = 0;

while (s[index])
{
_putchar(s[index]);
index++;
}
_putchar('\n');
}

/**
 * _putchar - putchar replica
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));/* alx putchar */
}

