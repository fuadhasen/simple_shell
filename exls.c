#include "main.h"

/**
 * excutels_l - Resolves a command with arguments using PATH.
 * @buf: Command and arguments entered by the user.
 *
 * Separates the command from its arguments, searches PATH for
 * the executable, and returns the resolved command with its arguments.
 *
 * Return: Resolved command with arguments, or NULL if not found.
 */

char *excutels_l(char *buf)
{
	char full[512];
	char *value;

	char *command = strtok(buf, " ");
	char *arguments = strtok(NULL, "\n");

	value = _getenv("PATH");
	if (value != NULL)
	{
		char *str = strtok(value, ":");
		if (str != NULL)
		{
			snprintf(full, sizeof(full), "%s/%s", str, command);
			if (access(full, F_OK) == 0)
			{
				if (arguments)
				{
					size_t len = _strlen(full) + _strlen(arguments) + 2;
					char *com_wiz_arg = malloc(len);
					snprintf(com_wiz_arg, len, "%s %s", full, arguments);
					return (com_wiz_arg);
				}
			}
			str = strtok(NULL, ":");
		}
	}
	return (NULL);
}
