#include "shell.h"

/**
 * main - Simple Shell main func
 * @ac: number of args
 * @av: args
 * Return: 0 (Always Success)
 */


extern char **environ;  // Add this line to declare environ

char **env;  // Definition of the env variable

int main(int ac, char **av)
{
    char *string = NULL, **cmd = NULL;
    int status = 0;
    (void)ac;

    // Initialize env using the external variable 'environ'
    env = environ;

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

        status = _execute(cmd, av);
    }

    return 0;
}
