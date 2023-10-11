#include "shell.h"

/**
 * _strchr - find a character in a string.
 * @str: the string to be used for finding
 * @ch: the character to be found
 *
 * Return: pointer of the character
 */

char *_strchr(const char *str, int ch)
{

while (*str != '\0')
{
if (*str == (char)ch)
{return ((char *)str);
}
str++;
}
if (ch == '\0')
return ((char *)str);
return (NULL);

}


/**
 * _strtok - a strtok replica which split a string into tokens
 * @str: the string/token to be split
 * @deli: the delimeter used to split the string
 *
 * Return: a pointer to token else NULL
 */

char *_strtok(char *str, const char *deli)
{

char *tkn_entry; /* hold token start position */
static char *tracker; /* keep track of the token */

if (str != NULL)
tracker = str;

if (tracker == NULL || *tracker == '\0')
return (NULL);

while (*tracker && _strchr(deli, *tracker))
{
tracker++;
}

if (*tracker == '\0')
return (NULL);

tkn_entry = tracker;

while (*tracker && _strchr(deli, *tracker))
{
tracker++;
}

if (*tracker)
{
*tracker = '\0';
tracker++;

}
else
tracker = NULL;
return (tnk_entry);
}


/**
 * _strcpy - a strcpy replica which copies a string from source to destination
 * @ori: the original source string to be copied
 * @tar: the target/ destination for the string
 *
 * Return: Apointer to the target string
 */

char *_strcpy(char *tar, const char *ori)
{

char *t = tar;

while ((*tar++ = *ori++))
;
return (t);
}


/**
 * _strlen - this is a strlen replica which counts the str lenght
 * @str: the string to be counted
 *
 * Return: lenght of the string.
 */

int _strlen(const char *str)
{

int count = 0;

while (s[count] != '\0')
count++;

return (count);
}


/**
 * _strcmp - replica for strcmp which compares two strings
 * @str1: the first string to be compared
 * @str2: the second string to be compared
 *
 * Return: 0 if both strngs are equal otherwise numbers greater or less than 0.
 */

int _strcmp(const char *str1, const char *str2)
{

while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
{
str1++;
str2++;

}

return (*str1 - *str2);
}
