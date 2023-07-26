#include "main.h"

void _puts_denied(char *prog_name, char *name, unsigned int c)
{
char *cnt = to_str(c);
_eputs(prog_name);
_eputs(": ");
_eputs(cnt);
_eputs(": ");
_eputs(name);
_eputs(": Permission denied\n");
free(cnt);
EXIT_ST = 126;
}
