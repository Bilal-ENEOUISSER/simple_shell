#include "shell.h"
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
		free(tmp), tmp = NULL;
		free(string), string = NULL;
		return (NULL);
	}
	while (token)
	{
		n++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (n + 1));
	if (!cmd)
	{
		free(string), string = NULL;
		return (NULL);
	}
	token = strtok(string, DELIM);
	while (token)
	{
		cmd[i] = _strdup(token);
		i++;
		token = strtok(NULL, DELIM);
	}
	cmd[i] = NULL;
	free(string), string = NULL;
	return (cmd);
}
