#include "main.h"

/**
 * _getenv - Retrieves an environment variable.
 * @name: Name of the environment variable to search for.
 *
 * Searches the process environment for a variable matching
 * the specified name.
 *
 * Return: The variable's value, or NULL if it does not exist.
 */

char* _getenv(const char* name) {

	int i;
    size_t name_len = _strlen(name);

    for (i = 0; environ[i] != NULL; ++i) {
        if (_strncmp(name, environ[i], name_len) == 0 && environ[i][name_len] == '=') {
            return environ[i] + name_len + 1; 
        }
    }

    return (NULL); 
}

