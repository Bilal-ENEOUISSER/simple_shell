#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in shell command.
 * @cmd: A pointer to a string representing the command.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */

int is_builtin(char *cmd)
{
	char *builtins[] = {
		"exit", "env", "setenv", 
		"cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
		return (1);
	}
	return (0);
}

/**
 * handle_builtin - Executes built-in shell commands.
 * @cmd: A pointer to an array of strings representing the command and its arguments.
 * @av: A pointer to an array of strings representing program arguments.
 * @status: A pointer to an integer representing the exit status of the program.
 * @idx: The index of the current command in the command array.
 * Return: void
 */
void handle_builtin(char **cmd, char **av, int *status, int idx)
{
	(void) av;
	(void) idx;

	if (_strcmp(cmd[0], "exit") == 0)
	exit_shell(cmd, status);

	else if (_strcmp(cmd[0], "env") == 0)
	print_env(cmd, status);
}

/**
 * exit_shell - Exits the shell program.
 * @cmd: A pointer to an array of strings representing the command and its arguments.
 * @status: A pointer to an integer representing the exit status of the program.
 * Return: void
 */
void exit_shell(char **cmd, int *status)
{
	free_arr(cmd);
	exit(*status);
}

/**
 * print_env - Prints the environment variables to the standard output.
 * @cmd: A pointer to an array of strings representing the command and its arguments.
 * @status: A pointer to an integer representing the exit status of the program.
 * Return: void
 */
void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_array(cmd);
	(*status) = 0;
}
