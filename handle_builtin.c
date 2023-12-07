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
	if (_strcmp(cmd[0], "exit") == 0)
	exit_shell(cmd, av, status, idx);

	else if (_strcmp(cmd[0], "env") == 0)
	print_env(cmd, status);
}

/**
 * exit_shell - Exits the shell program.
 * @cmd: A pointer to an array of strings representing the command and its arguments.
 * @status: A pointer to an integer representing the exit status of the program.
 * Return: void
 */
void exit_shell(char **cmd, char **av,  int *status, int idx)
{
	int exit_val = (*status);
	char *index, mssg[] = ": exit Illegal number: ";

	if (cmd[1])
	{
		if (is_positive(cmd[1]))
		{
			exit_val = _atoi(cmd[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_arr(cmd);
			(*status) = 2;
			return;
		}
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
	free_arr(cmd);
	(*status) = 0;
}
