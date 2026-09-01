#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @str: String to search.
 * @c: Character to find.
 *
 * Return: Pointer to the first occurrence of the character,
 * or NULL if the character is not found.
 */

char* _strchr(const char *str, char c)
{
	while(*str != '\0')
	{
		if(*str == c)
		{
			return (char*)str;
		}
		str++;
	}
	return NULL;
}
