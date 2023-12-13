#include "shell.h"

/**
 * set_env - Sets a new environment variable or modifies an existing one.
 * @cmd: A pointer to an array of strings representing the command
 * @av: arguments
 * @status: A pointer to an integer representing the exit status
 * @idx: index
 * Return: void
 */

void set_env(char **cmd, char **av,  int *status, int idx)
{
	if (cmd[1] && cmd[2])
	{
		if (setenv(cmd[1], cmd[2], 1) != 0)
		{
			perror("setenv");
			*status = 1;
		}
	}
	else
	{
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, _itoa(idx), _strlen(_itoa(idx)));
		write(STDERR_FILENO, ": Usage: setenv VARIABLE VALUE\n", 30);
		*status = 1;
	}
	free_arr(cmd);
}

/**
 * unset_env - Unsets (removes) an environment variable.
 * @cmd: A pointer to an array of strings representing the command
 * @av: arguments
 * @status: A pointer to an integer representing the exit status
 * @idx: index
 * Return: void
 */
void unset_env(char **cmd, char **av,  int *status, int idx)
{
	if (cmd[1])
	{
		if (unsetenv(cmd[1]) != 0)
		{
			perror("unsetenv");
			*status = 1;
		}
	}
	else
	{
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, _itoa(idx), _strlen(_itoa(idx)));
		write(STDERR_FILENO, ": Usage: unsetenv VARIABLE\n", 27);
		*status = 1;
	}
	free_arr(cmd);
}
