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

/**
 * split - splits a string
 * @string: string to split
 * Return: cmd
 */

char **split(char *string)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int n = 0, i = 0;

	if (!string)
		return (NULL);
	tmp = _strdup(string);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free (tmp), tmp = NULL;
		free (string), string = NULL;
		return (NULL);
	}
	while (token)
	{
		n++;
		token = strtok(NULL, DELIM);
	}
	free (tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (n + 1));
	if (!cmd)
	{
		free (string), string = NULL;
		return (NULL);
	}
	while (token)
        {
                cmd[i] = _strdup(token);
                token = strtok(NULL, DELIM);
		i++;
        }
	free (string), string = NULL;
        cmd[i] = NULL;
	return (cmd);
}

/**
 * _execute - execute the command
 * @cmd: command
 * @av: args
 * Return:
 */

int _execute(char **cmd, char **av)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
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

/**
 * free_arr - free arrays
 * @arr: array
 */

void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
