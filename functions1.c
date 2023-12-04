#include "shell.h"

char *read_cmd(void)
{
  char *cmd = NULL;
  s_t len = 0;
  ss_t j;

  write(STDOUT_FILENO, "$ ", 2);
  j = getline(&cmd, &len, stdin);
  if (j == -1)
    {
      free(cmd);
      return (NULL);
    }
  return (cmd);
}
