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
return (NULL);
_strcpy(ptr, s);

return (ptr);

}


/**
 * _atoi - atoi replica which convert string to integer
 * @str: the string to be converted
 *
 * Return: 0 if no convertion else the interger
 */

int _atoi(const char *str)
{
int r = 0;
int sign = 1;

while (*str == ' ' || (*str >= 9 && *str <= 13))
str++;
if (*str == '-' || *str == '+')
{
if (*str == '-')
sign = -1;
str++;
}
while (*str >= '0' && *str <= '9')
{
r = r * 10 + (*str - '0');
str++;
}

return (r *sign);
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

