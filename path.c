#include "simple_shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * find_command_in_path - Finds the full path of a command in the PATH environment variable
 * @command: Command to find
 * Return: Full path of the command if found, NULL otherwise
 */

char *find_command_in_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");
	struct stat st;
	char *full_path = malloc(strlen(path) + strlen(command) + 2);

	if (!full_path)
	{
		fprintf(stderr, "Memory Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	while (path != NULL)
	{
		sprintf(full_path, "%s/%s", path, command);
		if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		path = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}

/**
 * execute_command - Executes the given command with arguments
 * @args: Array of command arguments
 * Return: 1 if the shell should continue running, 0 otherwise
 */

int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path;

	if (args[0][0] == '/')
	{
		path = strdup(args[0]);
	}
	else
	{
		path = find_command_in_path(args[0]);
		if (path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			return (1);
		}
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			perror("Error");
		}
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(path);
	return (1);
}
