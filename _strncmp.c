#include "main.h"

/**
 * _strncmp - Compare two strings up to a certain number of characters.
 * @str1: First string.
 * @str2: Second string.
 * @n: Number of characters to compare.
 *
 * Return: 0 if strings are equal, positive if str1 > str2, negative if str1 < str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
    /* Loop through strings and compare characters */
    while (n > 0 && *str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
        n--;
    }

    if (n == 0)
        return 0;

    return (*str1 - *str2);
}

