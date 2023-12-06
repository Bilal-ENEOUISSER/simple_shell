#include "shell.h"

/**
 * _getpath - gats path
 * @cmd: command
 * Return: 
 */

char *_getpath(char *cmd)
{
	char *path_env, *full_cmd, *direc;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if(!path_env)
		return (NULL);
	direc = strtok(path_env, ":");
	whiel (direc)
	{
		full_cmd = malloc(_strlen(direc) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, direc);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
