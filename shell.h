#ifndef  SHELL_H
#define  SHELL_H

/* all the libraries for the custom shell */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

#define BUFFER_SIZE 1024
#define CUSTOM_DELIMETERS "\t\n"

/* prototypes used for string and print replicas*/
char *_strchr(const char *s, int ch);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *tar, const char *ori);
char _atoi(const char *str);
char *_strdup(const char *s);
char *_strcat(char *trg, char *ori);

/* for the main function calls */

char *prompt(void);
int exec_custom_cmd(char **cmd, char **args, int index);
char **split(char *input);
void _puts(const char *s);
void envi(void);
int _putchar(char ch);

/* extra prototypes */
void prerror(char *name, char *cmd_name, int i);
char *itoa(int value, char *buffer, int radix, int is_negative);
void free_array(char **str)
int count_digits(int value);
char *get_envi(const char *name);
char *get_full_path(char *input);

#endif
