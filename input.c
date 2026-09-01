#include "main.h"

/**
 *
 * print_prompt - Displays the shell prompt and flushes stdout.
 */
void print_prompt(void)
{
	_printf("$ ");
	fflush(stdout);
}

/**
 * read_input - Reads a command from a standard input.
 * @buffer: Pointer to the input buffer.
 * @size: Pointer to the size of the input buffer.
 *
 * Handles eof by terminating the shell
 */

void read_input(char **buffer, size_t *size)
{
	ssize_t read;
	read = getline(buffer, size, stdin);
	if (read == -1)
	{
		_printf("\n");
		exit_shell();
	}
	(*buffer)[read - 1] = '\0';
}


/**
 * input_is_exit - Checks whether the user entered the exit command.
 * @buf: The command entered by the user.
 *
 * Return: 1 if the command is "exit", otherwise 0.
 */
int input_is_exit(const char *buf)
{
	return (_strcmp(buf, "exit") == 0);
}
