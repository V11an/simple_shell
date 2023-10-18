#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Shell
{
	char **env;
}
Shell;

void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
void free_memory(char *line, char **args);
int handle_builtin_commands(char **args);
void execute_external_command(char **args);

#endif /* SIMPLE_SHELL_H */
