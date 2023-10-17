#ifndef  SHELL_H
#define  SHELL_H

/* all the libraries for the custom shell */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

#define BUFFER_SIZE 1024
#define CUSTOM_DELIMETERS "\t\n"
#define TOKEN_SIZE 100
#define PATH_SIZE 1050

/* prototypes used for string and print replicas*/
char *_strchr(const char *s, int ch);
char *_strtok(char *str, const char *deli);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *tar, const char *ori);
char _atoi(const char *str);
char *_strdup(const char *s);
char *_strcat(char *trg, char *ori);
char *_strstr(const char *str, const char *n_str);
char *_strpbrk(const char *str, const char *s_str);

/* for the main function calls */

void *prompt(char *cmd);
void start(void);
int execute_cmd(char *path, char **ptr, char **str, char *name);
char **split(char *str, char **tokens);
void _puts(const char *s);
int _putchar(char ch);
int _getline(void);
void *_realloc(void *old_ptr, size_t old_size);
void sighandler(int num);
void *_memset(void *dest, int value, size_t size);

/* extra prototypes */
void prerror(char *name, char *cmd_name, int i);
char *itoa(int value, char *buffer, int radix, int is_negative);
void farray(char **str);
int count_digits(int value);
char *get_envi(const char *name);
char *get_full_path(char *input);

#endif
