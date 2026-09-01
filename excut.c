#include "main.h"

/**
 * excute_command - Executes a command using a child process.
 * @buf: Path to the executable command.
 * @av: Command-line arguments passed to the shell.
 *
 * Creates a child process with fork(), executes the command
 * using execve(), and waits for the child process to finish.
 */

void excute_command_args(char *buf, char *av[])
{
	pid_t child;
	char *arg[256];
	int i = 0;

	char *str = strtok(buf, " ");
	while (str != NULL)
	{
		arg[i++] = str;
		str = strtok(NULL, " ");
	}
	arg[i] = NULL;

	child = fork();
	if (child == -1)
	{
		perror("fork fail");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(arg[0], arg, environ) == -1)
		{
			_printf("%s: No such file or directory\n", av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
