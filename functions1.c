#include "shell.h"

/**
 * _getline - it reads a single character from standard input.
 *
 * Return: The character otherwise or error.
 */
int _getline(void)
{
	ssize_t b_read = read(0,  input_char, 1);
    char input_char;

	if (b_read == -1)
	{
		perror("Error from reading");
		exit(EXIT_FAILURE);
	}
	else if (b_read == 0)
		return (EOF);
    
	else
	{
		return ((int) input_char);
	}
}

#include "main.h"

/**
 * _realloc - Reallocate memory for a pointer with a new size
 * @ptr: Pointer to the memory to reallocate
 * @size: New size of the memory
 *
 * Return: Pointer to the reallocated memory
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t copy_size;
	char *d;
	const char *s;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(size));

	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);

	copy_size = size;

	if (copy_size > sizeof(ptr))
		copy_size = sizeof(ptr);

	d = (char *)new_ptr;
	s = (const char *)ptr;

	while (copy_size--)
		*d++ = *s++;

	free(ptr);

	return (new_ptr);
}



/**
 * sighand - a custom signal handler which interrupting a process.
 * @num: signal number received.
 * 
 * Return: nothing
 */
void sighand(int num)
{
	(void) num;
    /* write a message to the standard error stream (usually the console)*/
	write(STDERR_FILENO, "\n$ ", 3);
	fflush(stdout);
}

