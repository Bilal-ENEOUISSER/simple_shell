#include "shell.h"

/**
 * main - Simple Shell main func
 * @ac: number of args
 * @av: args
 * Return: 0 (Always Success)
 */

int main(int ac, char **av)
{
	char *line = NULL;
	int status = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		line = read_cmd();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		free (line);
	}
	return (0);
}
