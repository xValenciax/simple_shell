#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BUFF_SIZE 1024

extern char **environ;

void shell(void);
int shell_handler(char []);
int run_command(char *[], char *[]);

char **args_split(char *);
char *trim_string(char *);
unsigned int count_words(char *);

void *_calloc(unsigned int, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *, char *, int);

int _atoi(char *);
int _strlen(char *);
int _putchar(char);
void _puts(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
int _strcmp(char *, char *);
char *_strdup(char *);
char *_strchr(char *, char);
char *_strpbrk(char *, char *);
char *_strstr(char *, char *);
int _isalpha(int);
int _isdigit(int);


#endif
