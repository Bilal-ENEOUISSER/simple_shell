#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main()
{
char *prompt = "#cisfun$ ", *new_line = "\n";
char *lineptr;
size_t n = 0;
while (1)
{
_puts(prompt);
getline(&lineptr, &n, stdin);
/*handle if lineptr is a valid command*/
/*handle if lineptr is not EOF*/
_puts(lineptr);
_puts(new_line);
free(lineptr);
}
return (0);
}
