#include "main.h"

/**
* _strcmp - compare the string
 * @str1: string one
 * @str2: string two
 *
 * Return: True or False
 */

int _strcmp(const char* str1, const char* str2)
{
	int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return (str1[i] - str2[i]);
}

