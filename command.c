#include "main.h"

/**
 *
 *
 *
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
