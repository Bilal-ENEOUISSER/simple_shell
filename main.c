#include "shell.h"

/**
 * main - Simple Shell main func
 * @ac: number of args
 * @av: args
 * Return: 0 (Always Success)
 */

int main(int ac, char **av)
{
	char *string = NULL, **cmd = NULL;
	int status = 0, idx = 0;
	(void)ac;

	while (1)
	{
		string = read_cmd();
		if (string == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		cmd = split(string);
		if (!cmd)
			continue;
		if (is_builtin(cmd[0]))
			handle_builtin(cmd, av, &status, idx);
		else
			status = _execute(cmd, av, idx);
	}
	free(string);
	return (0);
}
