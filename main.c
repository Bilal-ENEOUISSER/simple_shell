#include "shell.h"

/**
 * main - Simple Shell main func
 * @ac: number of args
 * @av: args
 * Return: 0 (Always Success)
 */
char **env;

int main(int ac, char **av, **envp)
{
	char *string = NULL, **cmd = NULL;
	int status = 0;
	(void)ac;

	env = envp;
	while (1)

	{
		string = read_cmd();
		if (string == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		cmd = split(string);
		if (!cmd)
			continue;
	}
	status = _execute(cmd, av);
	return (0);
}
