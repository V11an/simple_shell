#include "shell.h"

/**
 * parse_arguments - Parse command line arguments.
 * @command: The command to be parsed.
 * @args: Array to store parsed arguments.
 * Return: Number of arguments parsed.
 */

int parse_arguments(char *command, char **args)
{
	int count = 0;
	char *token;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[count++] = strdup(token);
		token = strtok(NULL, " ");
	}

	args[count] = NULL;
	return (count);
}
