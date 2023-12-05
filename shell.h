#ifndef SHELL_H
#define SHELL_H
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Global environemnt */
extern char **environ;

/*string functions*/
char *starts_with(const char *str1, const char *str2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);

/*linked lists functions*/

#endif
