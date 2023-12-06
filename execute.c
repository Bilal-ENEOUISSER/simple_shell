#include "shell.h"
/**
 * _execute - execute the command
 * @cmd: command
 * @av: args
 * Return: exit status of the command
 */

int _execute(char **cmd, char **av, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_path = _getpath(cmd[0]);
	if (!full_cmd)
	{
		printerr(av[0], cmd[0], idx);
		free_arr(cmd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free_arr(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(cmd);
		free(full_cmd), full_cmd = NULL; 
	}
	return (WEXITSTATUS(status));
}
