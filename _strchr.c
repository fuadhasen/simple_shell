#include "main.h"

/**
 *
 *
 *
 *
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
