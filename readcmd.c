#include "shell.h"

/**
 * read_cmd - gets the next line of input from STDIN
 * Return: cmd
 */

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t length = 0;
	ssize_t j;

	if(isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	j = getline(&cmd, &length, stdin);
	if (j == -1)
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
