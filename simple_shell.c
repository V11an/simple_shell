#include "simple_shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * display_prompt - Displays the shell prompt
 */

void display_prompt(void)
{
	printf("$ ");
}

/**
 * read_line - Reads a line of input from the user
 * Return: The input line read from the user
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * parse_line - Parses the input line into tokens
 * @line: Input line to be parsed
 * Return: Array of tokens
 */

char **parse_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Memory Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Memory Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute_command - Executes the given command
 * @args: Array of command arguments
 * Return: 1 if the shell should continue running, 0 otherwise
 */

int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			(void)wpid;
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * free_memory - Frees the allocated memory for input line and arguments
 * @line: Input line to be freed
 * @args: Array of arguments to be freed
 */

void free_memory(char *line, char **args)
{
	int i = 0;

	free(line);
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
