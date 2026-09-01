#include "main.h"
#include "stdarg.h"

/**
 * main - Entry point of the Simple Shell program.
 * @ac: Number of command-line arguments.
 * @av: Array of command-line arguments.
 * 
 * Return: 0 on successful Excution.
 */

int main(int ac, char *av[])
{
	run_shell(ac, av);
	return (0);
}
