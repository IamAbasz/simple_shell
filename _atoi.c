#include "hsh.h"

/**
 * @str: String input.
 * Return: The converted integer.
 * customAtoi - Converts a string to an integer.
 */
int customAtoi(char *str)
{
    unsigned int count = 0, size = 0, result = 0, isNegative = 1, multiplier = 1, i;

    while (*(str + count) != '\0')
    {
        if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
            break;

        if (*(str + count) == '-')
            isNegative *= -1;

        if (((str + count) >= '0') && ((str + count) <= '9'))
        {
            if (size > 0)
                multiplier *= 10;
            size++;
        }
        count++;
    }

    for (i = count - size; i < count; i++)
    {
        result = result + ((*(str + i) - '0') * multiplier);
        multiplier /= 10;
    }
    
    return (result * isNegative);
}
