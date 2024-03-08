#include <stdio.h>
#include <string.h> // for strchr
#include <unistd.h> // for environ
#include "main.h"

/**
 * env - function env
 *
 * Return: void
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

