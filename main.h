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
#include <signal.h>
#include <dirent.h>

#define BUFF_SIZE 1024
#define PROMPT "($) "
#define PATH "PATH"

#define ERR_NOT_FOUND 127
#define ERR_NO_FORK -8
#define ERR_NO_WAIT -7
#define ERR_NO_SPLIT -6
#define ERR_NO_EXEC -5
#define DIR_NOT_FOUND 2
#define PERM_DENIED 126

extern char **environ;
int EXIT_ST;

int shell(char *);
int shell_handler(char []);
int run_command(char *[], char *[], char *);
char *full_path(char *, char *);

char **args_split(char *);
char *trim_string(char *);
unsigned int count_words(char *);
void _puts_not_found(char *, char *, unsigned int);
void _puts_denied(char *, char *, unsigned int);
void _puts_invalid_exit(char *, char *, unsigned int);
void sigint_handler(int);
char *_getenv(char *);
void builtin_exit(int);
int check_command(char *, char *[]);
void print_env(void);

void *_calloc(unsigned int, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void afree(char **);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *, char *, unsigned int);

int _atoi(char *);
int _strlen(char *);
int _putchar(char);
void _puts(char *);
void rev_string(char *);
int _eputchar(char);
void _eputs(char *);
int starts_with(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
int _strcmp(char *, char *);
char *_strdup(char *);
char *_strrchr(char *, char);
char *_strpbrk(char *, char *);
char *_strstr(char *, char *);
char *to_str(unsigned int);
int _isalpha(int);
int _isdigit(int);

#endif
