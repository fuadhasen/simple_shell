#include "main.h"


/**
* excute_command - Executes a command using a child process.
 * @buf: Path to the executable command.
 * @av: Command-line arguments passed to the shell.
 *
 * Creates a child process with fork(), executes the command
 * in the child using execve(), and waits for the child
 * process to finish in the parent.
 */

void excute_command(char *buf, char *av[])
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("fork fail\n");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		char *arg[2];
		arg[0] = buf;
		arg[1] = NULL;
		if (execve(arg[0], arg, environ) == -1)
		{
			_printf("%s: No such file or directory\n", av[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// wait(NULL);
	}
}
