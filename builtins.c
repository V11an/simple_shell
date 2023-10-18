#include "simple_shell.h"
#include <string.h>

int handle_builtin_commands(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}

	if (strcmp(args[0], "echo") == 0)
	{
		int i = 1;

		while (args[i] != NULL)
		{
			printf("%s ", args[i]);
			i++;
		}
		printf("\n");
		return (1);
	}

	return (-1);
}

int execute_command(char **args)
{
	int result = handle_builtin_commands(args);

	if (result >= 0)
	{
		return (result);
	}

	execute_external_command(args);
	return (1);
}
