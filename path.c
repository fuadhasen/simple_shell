#include "main.h"

/**
 * path - Finds the executable path of a command.
 * @buf: Command name to search for.
 *
 * Searches the directories listed in the PATH environment
 * variable and returns the full path of the executable.
 *
 * Return: Full executable path if found, otherwise NULL.
 */

char *path(char *buf)
{
	char full[100];
	const char *value, *path_cpy;

	if (_strchr(buf, ' ') != NULL)
	{
		return (excutels_l(buf));
	}
	else
	{
		value = _getenv("PATH");
		path_cpy = _strdup(value);
		if (path_cpy != NULL)
		{
			char *str = strtok((char *)path_cpy, ":");
			while (str != NULL)
			{
				snprintf(full, sizeof(full), "%s/%s", str, buf);
				if (access(full, F_OK) == 0)
				{
					char *res = _strdup(full);
					return (res);
				}
				str = strtok(NULL, ":");
			}
		}
	}
	return (NULL);
}
