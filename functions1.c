#include "shell.h"
/**
 * read_cmd - gets the next line of input from STDIN
 * @length: size of preallocated ptr buffer if not NULL
 * Return: cmd
 */

char *read_cmd(void)
{
  char *cmd = NULL;
  s_t length = 0;
  ss_t j;
  if(isatty(STDIN_FILEON))
  write(STDOUT_FILENO, "$ ", 2);
  j = getline(&cmd, &length, stdin);
  if (j == -1)
    {
      free(cmd);
      return (NULL);
    }
  return (cmd);
}
