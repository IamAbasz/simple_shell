#include "hsh.h"

/**

changeToParentDirectory - Changes to the parent directory.

@data: Relevant data for the operation (environment variables).

Return: No return.
*/
void cdParentDirectory(data_input *data)
{
    char currentDirectory[PATH_MAX];
    char *directory, *copiedPwd, *copiedStrtokPwd;

    getcwd(currentDirectory, sizeof(currentDirectory));
    copiedPwd = _strdup(currentDirectory);
    set_env("OLDPWD", copiedPwd, data);

    directory = data->args[1];

    if (_strcmp(".", directory) == 0)
    {
        set_env("PWD", copiedPwd, data);
        free(copiedPwd);
        return;
    }

    if (_strcmp("/", copiedPwd) == 0)
    {
        free(copiedPwd);
        return;
    }

    copiedStrtokPwd = copiedPwd;
    rev_string(copiedStrtokPwd);
    copiedStrtokPwd = _strtok(copiedStrtokPwd, "/");

    if (copiedStrtokPwd != NULL)
    {
        copiedStrtokPwd = _strtok(NULL, "\0");

        if (copiedStrtokPwd != NULL)
            rev_string(copiedStrtokPwd);
    }

    if (copiedStrtokPwd != NULL)
    {
        chdir(copiedStrtokPwd);
        set_env("PWD", copiedStrtokPwd, data);
    }
    else
    {
        chdir("/");
        set_env("PWD", "/", data);
    }

    data->status = 0;
    free(copiedPwd);
}

/**
 * cdToDirectory - Changes to a directory given by the user
 *
 * @data: Data relevant for the operation (directories)
 * Return: No return
 */
void cdToDirectory(data_input *data)
{
    char currentDirectory[PATH_MAX];
    char *directory, *copiedPwd, *copiedDir;

    getcwd(currentDirectory, sizeof(currentDirectory));
    directory = data->args[1];

    if (chdir(directory) == -1)
    {
        /* handle error */
        return;
    }

    copiedPwd = _strdup(currentDirectory);
    set_env("OLDPWD", copiedPwd, data);

    copiedDir = _strdup(directory);
    set_env("PWD", copiedDir, data);

    free(copiedPwd);
    free(copiedDir);

    data->status = 0;

    chdir(directory);
}

/**
 * cdPreviousDirectory - Changes to the previous directory
 *
 * @data: Data relevant for the operation (environ)
 * Return: No return
 */
void cdPreviousDirectory(data_input *data)
{
    char currentDirectory[PATH_MAX];
    char *previousPwd, *previousOldPwd, *copiedPwd, *copiedOldPwd;

    getcwd(currentDirectory, sizeof(currentDirectory));
    copiedPwd = _strdup(currentDirectory);

    previousOldPwd = _getenv("OLDPWD", data->_environ);

    if (previousOldPwd == NULL)
        copiedOldPwd = copiedPwd;
    else
        copiedOldPwd = _strdup(previousOldPwd);

    set_env("OLDPWD", copiedPwd, data);

    if (chdir(copiedOldPwd) == -1)
        set_env("PWD", copiedPwd, data);
    else
        set_env("PWD", copiedOldPwd, data);

    previousPwd = _getenv("PWD", data->_environ);

    write(STDOUT_FILENO, previousPwd, _strlen(previousPwd));
    write(STDOUT_FILENO, "\n", 1);

    free(copiedPwd);
    
    if (previousOldPwd)
        free(copiedOldPwd);

    data->status = 0;

    chdir(previousPwd);
}

/**
 * cdToHomeDirectory - Changes to the home directory
 *
 * @data: Data relevant for the operation (environ)
 * Return: No return
 */
void cdToHomeDirectory(data_input *data)
{
    char *copiedPwd, *homeDirectory;
    char currentDirectory[PATH_MAX];

    getcwd(currentDirectory, sizeof(currentDirectory));
    copiedPwd = _strdup(currentDirectory);

    homeDirectory = _getenv("HOME", data->_environ);

    if (homeDirectory == NULL)
    {
        set_env("OLDPWD", copiedPwd, data);
        free(copiedPwd);
        return;
    }

    if (chdir(homeDirectory) == -1)
    {
        /* handle error */
        free(copiedPwd);
        return;
    }

    set_env("OLDPWD", copiedPwd, data);
    set_env("PWD", homeDirectory, data);
    
    free(copiedPwd);
    data->status = 0;
}

