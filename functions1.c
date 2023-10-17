#include "shell.h"

/**
 * _getline - it reads a single character from standard input.
 *
 * Return: the character otherwise or error.
 */
int _getline(void)
{
char input_char;
ssize_t b_read;
b_read = read(0,  input_char, 1);

if (b_read == -1)
{
perror("reading error");
exit(EXIT_FAILURE);
}
else if (b_read == 0)
return (EOF);
    
else
{
return ((int) input_char);
}
}

/**
 * _realloc - realloc replica which reallocate memory for a pointer with a new size
 * @old_ptr:  to be reallocate
 * @old_size: the neew size of the memory
 *
 * Return: pointer to the new reallocated memory
 */
void *_realloc(void *old_ptr, size_t old_size)
{
size_t new_size;
void *new_ptr;
char *f;
const char str;

if (old_size == 0)
{
free(old_ptr);
return (NULL);
}

if (old_ptr == NULL)
return (malloc(new_size));

new_ptr = malloc(old_size);

if (new_ptr == NULL)
return (NULL);
new_size = old_size;

if (new_size > sizeof(old_size))
new_size = sizeof(old_ptr);

f = (char *)new_ptr;
str = (const char *)old_ptr;

while (new_size--)
*f++ = *str++;

free(old_ptr);

return (new_ptr);
}

/**
 * sighand - a custom signal handler which interrupting a process.
 * @num: signal number received.
 * 
 * Return: nothing
 */

void sighandler(int num)
{
(void) num;
/* write a message to the standard error stream (usually the console)*/
write(STDERR_FILENO, "\n$ ", 3);
fflush(stdout);
}

/**
 * _memset - memset replica which Set the memory pointed to by dest to the specified value for a given number of bytes.
 * @dest: Pointer to the memory to be filled.
 * @value: The value to set in each byte.
 * @size: Number of bytes to be set.
 * 
 * Return: A pointer to the memory area 'dest'.
 */

void *_memset(void *dest, int value, size_t size)
{
unsigned char *ptr = (unsigned char *)dest;
unsigned char byte_value = (unsigned char)value;

while (size-- > 0)
*ptr++ = byte_value;

return (dest);
}

/**
 * farray - Free a 2d array of tokesn.
 *  @str: The 2d array of tokens to be freed.
 * 
 * Return: nothing 
 */

void farray(char **str)
{
int n;

if (str == NULL)
return;

for (n = 0; str[n] != NULL; n++)
free(str[n]);
}
