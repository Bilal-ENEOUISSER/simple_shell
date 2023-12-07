#include "shell.h"

/**
 * is_positive - checks if a number is positive or not
 * @str: array of string
 * Return: 1 if a number is positive, otherwise 0
 */

int is_positive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - convert ascii to integer
 * @str: array of string
 * Return: a number
 */

int _atoi(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}
