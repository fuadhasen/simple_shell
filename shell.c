#include "main.h"

/**
 * run_shell - Runs the main loop of the Simple Shell.
 * @ac: Number of command-line arguments.
 * @av: Array of command-line arguments.
 *
 * Displays the prompt, reads user input, handles built-in
 * commands, and executes external commands until the shell exits.
 */

void run_shell(int ac, char *av[])
{
	char *buffer = NULL;
	size_t size = 0;
	int t = 1;
	(void)(ac);

	while (t)
	{
		print_prompt();
		read_input(&buffer, &size);
		if (input_is_exit(buffer))
		{
			exit_shell();
		}
		if (_strcmp(buffer, "env") ==0)
		{
			env();
		}
		else
		{
			execute_command_or_args(buffer, av);
		}
	}
	free(buffer);
}
