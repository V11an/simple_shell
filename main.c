#include "simple_shell.h"

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
