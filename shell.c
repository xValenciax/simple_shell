#include "main.h"

int run_command(char *args[], char *env[])
{
  pid_t cpid;
  int Wstatus, w;

  cpid = fork();

  if (cpid == -1)
    return (-1);

  else if (cpid == 0)
      execve(args[0], args, env);

  else
    {
      w = waitpid(cpid, &Wstatus, 0);

      if (w == -1)
	return (-1);
    }

  return (0);
}

int shell_handler(char command[])
{
  char *args[50], **ret;
  int exec = 0, i = 0;

  ret = args_split(command);
  
  if (!ret)
    return (-1);
  
  while (ret[i])
    {
      args[i] = ret[i];
      i++;
    }

  args[i] = NULL;
  free(ret);

  exec = run_command(args, __environ);

  if (exec < 0)
    return (exec);

  return (0);
}

void shell(void)
{
  char *command = NULL, prompt[9] = "(Selim$) ", *new_cmnd;
  size_t n = 0;
  
  write(1, &prompt[0], 9);
  
  while (getline(&command, &n, stdin) != -1)
    {
      fflush(stdin);
      
      if (command)
	{
	  new_cmnd = trim_string(command);
	  shell_handler(new_cmnd);
	  free(new_cmnd);
	}
      free(command);
      write(1, &prompt[0], 9);
    }
}
