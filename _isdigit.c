#include "hsh.h"

/**
 * isStringNumeric - Checks if the given string represents a numeric value.
 *
 * @str: String input to be checked.
 * Return: Returns 1 if the string is numeric, else returns 0.
 */
int isStringNumeric(const char *str)
{
    unsigned int index;

    for (index = 0; str[index]; index++)
    {
        if (str[index] < '0' || str[index] > '9')
            return 0;
    }

    return 1;
}
