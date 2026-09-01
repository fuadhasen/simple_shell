#include <stdio.h>
#include <string.h> // for strchr
#include <unistd.h> // for environ
#include "main.h"

/**
  * env - Prints the current environment variables.
 *
 * Iterates through the process environment and prints
 * each environment variable to standard output.
 */

void env(void) 
{
	char **env = environ;
	while (*env != NULL) 
	{
		char *equal_sign = _strchr(*env, '=');

		if (equal_sign != NULL) 
		{

            *equal_sign = '\0';
            printf("%s=%s\n", *env, equal_sign + 1);
            *equal_sign = '=';
        }

        env++;
    }
}

