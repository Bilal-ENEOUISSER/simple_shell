#include "shell.h"
/**
 * _execute - execute the command
 * @cmd: command
 * @av: args
 * Return: exit status of the command
 */

int _execute(char **cmd, char **av)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(av[0]);
			free_arr(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(cmd);
	}
	return (WEXITSTATUS(status));
}
