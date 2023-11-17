#include "hsh.h"

/**
 * compareEnvName - Compares environment variable names with the given name.
 * @envVarName: Name of the environment variable.
 * @name: Name to be compared.
 *
 * Return: 0 if the names are not equal; otherwise, returns the length of the matching prefix.
 */
int compareEnvName(const char *envVarName, const char *name)
{
    int i;

    for (i = 0; envVarName[i] != '='; i++)
    {
        if (envVarName[i] != name[i])
        {
            return 0;
        }
    }

    return (i + 1);
}

