#include "hsh.h"

/**
 * main - Entry point for the shell program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on successful execution.
 */
int main(int __attribute__((unused)) argc, char **argv)
{
    ShellData shellData;

    // Set up signal handling for Ctrl+C (SIGINT)
    signal(SIGINT, handleSIGINT);

    // Initialize shell data structure with command-line arguments
    initializeShellData(&shellData, argv);

    // Start the main loop for shell prompt
    promptLoop(&shellData);

    // Free allocated memory and resources
    freeShellData(&shellData);

    return 0;
}

