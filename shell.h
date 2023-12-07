#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'
#define DELIM " \t\n"
extern char **environ;

void free_arr(char **arr);
char *read_cmd(void);
char **split(char *string);
int _execute(char **cmd, char **av, int idx);
char *_getenv(char *var);
char *_getpath(char *cmd);

/* strings.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);


/*tools*/
void printerr(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_str(char *str, int len);
#endif
