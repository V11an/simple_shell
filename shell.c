#include "shell.h"

/**
 * execute_command - Execute the given command.
 * @command: The command to be executed.
 * Return: 1 on success, 0 on failure.
 */

int execute_command(char *command)
{
	char *args[100];
	int num_args = parse_arguments(command, args);
	pid_t child_pid;
	int status;
	int i;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	for (i = 0; i < num_args; ++i)
	{
		free(args[i]);
	}
	return (1);
}
