#include "shell.h"

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
