#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int execute_command(char *command);
int parse_arguments(char *command, char **args);
int exit_command(char *command);

#endif /* SHELL_H */
