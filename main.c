#include "simple_shell.h"

/**
 * main - Entry point of the shell program
 * Return: 0 on success, otherwise 1
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		display_prompt();
		line = read_line();
		args = parse_line(line);
		status = execute_command(args);
		free_memory(line, args);
	} while (status);

	return (EXIT_SUCCESS);
}
