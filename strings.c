#include "shell.h"
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int i, length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	  {
	    length++;
	    str++;
	  }
	str = str - len
	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		ret[i] = str[i];
	return (ret);
}




/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
  int cmp;
  cmp = (int)*s1 - (int)*s2;
  while (*s1)
    {
      if (*s1 != *s2)
	break;
      s1++;
      s2++;
      cmp = (int)*s1 - (int)*s2;
    }
  return (cmp);
}


/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}


/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
  char *ret = dest;
  while (*ret)
    ret++;
  while (*src)
    {
      *ret = *src;
      ret++;
      src++;
    }
  *ret = *src;
  return (dest);
}



/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
