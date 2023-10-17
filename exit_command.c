#include "shell.h"

/**
 * exit_command - Execute the given command.
 * @command: The command to be executed.
 * Return: 1 on success, 0 on failure.
 */

int exit_command(char *command)
{
	char *args[100];
	int num_args = parse_arguments(command, args);

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(args[0]) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, args[0]);

		if (access(full_path, X_OK) == 0)
		{
			if (execve(full_path, args, environ) == -1)
			{
				perror("execve");
				free(full_path);
				return (0);
			}
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", args[0]);
	return (0);
}
