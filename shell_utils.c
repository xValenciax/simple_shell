#include "main.h"

char *trim_string(char *str)
{
  int i = 0, isalpha = 0;
  char *ret = malloc(strlen(str) + 1);

  while (str[i])
    {
      if (!str[i + 1] && (str[i] == ' ' || str[i] == '\n'))
	break;
      if (_isalpha(str[i]))
	isalpha = 1;
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  if (!isalpha)
    {
      free(ret);
      return (NULL);
    }
    
  return (ret);
}

unsigned int count_words(char *str)
{
  unsigned int len = 0, i = 0 ;

  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	len++;
      i++;
    }

  return (len + 1);
}

char **args_split(char *str)
{
  char *tok;
  char **words = NULL;
  int i = 0, count = 0;

  if (!str)
    return NULL;

  count = count_words(str);
  words = malloc(sizeof(*words) * (count + 1));

  if (!words)
    return (NULL);
  
  tok = strtok(str, " ");
  while (tok && i < count) {
    words[i] = tok;
    i++;
    tok = strtok(NULL, " ");
  }

  words[i] = NULL;
  
  return words;
}

void _puts_not_found(char *prog_name, char *name, unsigned int c)
{
  char *cnt = to_str(c);
  _eputs(prog_name);
  _eputs(": ");
  _eputs(cnt);
  _eputs(": ");
  _eputs(name);
  _eputs(": not found\n");
  free(cnt);
  EXIT_ST = 127;
}

void sigint_handler(__attribute__((unused))int sig)
{
  _putchar('\n');
  _puts(PROMPT);
  EXIT_ST = 130;
}
