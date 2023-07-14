#include "main.h"

/**
 * run_command - forks a new process to run the command
 *
 * @args: array of arguments from the stdin
 * @env: environment of the current running process
 *
 * Return: 0 (Success), negative number (Failure)
 */

int run_command(char *args[], char *env[])
{
pid_t cpid = -1;
int Wstatus, w;

if (access(args[0], X_OK) != -1)
cpid = fork();
else
return (ERR_NOT_FOUND);

if (cpid == -1)
return (ERR_NO_FORK);

else if (cpid == 0)
{
if (execve(args[0], args, env) == -1)
return (ERR_NO_EXEC);
}

else
{
w = waitpid(cpid, &Wstatus, 0);

if (w == -1)
return (ERR_NO_WAIT);
}

return (0);
}

/**
 * shell_handler - process the inputs before running it
 *
 * @command: command from stdin before preprocessing
 *
 * Return: 0 (Success), negative number (Failure)
 */

int shell_handler(char command[])
{
char *args[BUFF_SIZE], **ret;
int exec = 0, i = 0;

ret = args_split(command);

if (!ret)
return (ERR_NO_SPLIT);

while (ret[i])
args[i] = ret[i], i++;

args[i] = NULL;
free(ret);

exec = run_command(args, __environ);
return (exec);
}

/**
 * shell - main shell function
 *
 * @prog_name: name of the executable file
 *
 * Return: 0 (Exit_Success), negative (Exit_Failure)
 */

int shell(char *prog_name)
{
char *command = NULL, *new_cmnd;
unsigned int cnt = 0;
int ret, gtret;
size_t n = 0;
const int IS_ATTY = isatty(STDIN_FILENO);

signal(SIGINT, sigint_handler);
if (IS_ATTY)
_puts(PROMPT);
while ((gtret = getline(&command, &n, stdin)) != -1)
{
if (command)
{
cnt++;
new_cmnd = trim_string(command);
if (new_cmnd)
ret = shell_handler(new_cmnd);
if (ret == ERR_NOT_FOUND)
_puts_not_found(prog_name, new_cmnd, cnt);
if (new_cmnd)
free(new_cmnd);
}
if (IS_ATTY)
_puts(PROMPT);
}
free(command);
if (IS_ATTY)
_putchar('\n');
if (!EXIT_ST)
EXIT_ST = 0;
exit(EXIT_ST);
}
