#include "hsh.h"

/**
 * compareChars - Compares characters of strings.
 * @str: Input string.
 * @delim: Delimiter.
 *
 * Return: 1 if the characters are equal, 0 otherwise.
 */
int compareChars(char str[], const char *delim)
{
    unsigned int i, j, matchingCount;

    for (i = 0, matchingCount = 0; str[i]; i++)
    {
        for (j = 0; delim[j]; j++)
        {
            if (str[i] == delim[j])
            {
                matchingCount++;
                break;
            }
        }
    }

    if (i == matchingCount)
        return 1;
    return 0;
}

