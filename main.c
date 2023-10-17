#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Description:
 * This function implements a basic shell. It continuously prompts the user
 * for input, reads the command from standard input, and executes it. If the
 * command is not found, it prints an error message to stderr. The program
 * exits when the user inputs an EOF character (typically Ctrl+D).
 *
 * Return: 0 on successful execution.
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1)
	{
		printf("($) ");
		characters = getline(&line, &bufsize, stdin);

		if (characters == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		if (line[characters - 1] == '\n')
		{
			line[characters - 1] = '\0';
		}

		if (execute_command(line) == 0)
		{
			fprintf(stderr, "%s: command not found\n", line);
		}
	}

	free(line);
	exit(EXIT_SUCCESS);
}
