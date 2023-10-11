#ifndef "SHELL_H"
#define "SHELL_H"

/* all the libraries for the custom shell */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/* prototypes used for string replicas*/
char *_strchr(const char *s, int ch);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *tar, const char *ori);
char _atoi(const char *str);
char *_strdup(const char *s);
char *_strcat(char *trg, char *ori);

/* buildins prototypes */




#endif
