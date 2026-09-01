#include "main.h"

/**
 * execute_command_or_args - Resolves and executes a shell command.
 * @buffer: Command entered by the user.
 * @av: Program command-line arguments.
 *
 * Handles commands given as absolute paths or resolves commands
 * through PATH before executing them with or without arguments.
 */

void execute_command_or_args(char *buffer, char *av[])
{
	if (buffer[0] == '/')
	{
		if (_strchr(buffer, ' ') == NULL)
		{
			excute_command(buffer, av);
		}
		else
		{
			excute_command_args(buffer, av);
		}
	}
	else
	{
		char *f = path(buffer);
		if (f != NULL)
		{
			if (_strchr(f, ' ') == NULL)
			{
				excute_command(f, av);
			}
			else
			{
				excute_command_args(f, av);
			}
		}
		free(f);
	}
}
