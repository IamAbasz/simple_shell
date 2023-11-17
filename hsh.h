#ifndef HSH_H
#define HSH_H

extern char **environ;

#define BUFSIZE
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <limits.h>
#include <linux/limits.h>

/**
 * struct ShellData - Contains all relevant data on the runtime.
 * @argv: Arguments count.
 * @input_line: Command line entered by the user.
 * @tokens: Tokens of the command line.
 * @command_status: Last status of the shell command.
 * @line_count: Lines counter.
 * @environment: Environment variables.
 * @shell_pid: Process ID of the shell.
 */
typedef struct ShellData
{
    char **argv;
    char *input_line;
    char **tokens;
    int command_status;
    int line_count;
    char **environment;
    char *shell_pid;
} ShellData;

/**
 * struct VariableNode - Single linked list to store variables.
 * @variable_length: Length of the variable.
 * @value: Value of the variable.
 * @value_length: Length of the value.
 * @next: Next node.
 */
typedef struct VariableNode
{
    int variable_length;
    char *value;
    int value_length;
    struct VariableNode *next;
} VariableNode;

/**
 * struct SeparatorNode - Single linked list to store separators.
 * @separator: ; | &
 * @next: Next node.
 */
typedef struct SeparatorNode
{
    char separator;
    struct SeparatorNode *next;
} SeparatorNode;

/**
 * struct CommandLineNode - Single linked list to store command lines.
 * @line: Command line.
 * @next: Next node.
 */
typedef struct CommandLineNode
{
    char *line;
    struct CommandLineNode *next;
} CommandLineNode;

/**
 * struct BuiltinCommand - Builtin struct for command args.
 * @name: The name of the command builtin (e.g., cd, exit, env).
 * @function: Pointer to the corresponding function.
 */
typedef struct BuiltinCommand
{
    char *name;
    int (*function)(ShellData *shell_data);
} BuiltinCommand;

void handleSIGINT(int signal);
int getNumberLength(int number);
void promptLoop(ShellData *shell_data);
char *intToString(int number);
char *duplicateString(const char *source);
char *readCommandLine(int *readLine);
void freeShellData(ShellData *shell_data);
void initializeShellData(ShellData *shell_data, char **arguments);
char *removeComments(char *input);
int checkSyntaxError(ShellData *shell_data, char *input);
char *replaceVariables(char *input, ShellData *shell_data);
int splitCommands(ShellData *shell_data, char *input);
void *customRealloc(void *pointer, unsigned int old_size, unsigned int new_size);
int getStringLength(const char *string);
void customMemcpy(void *newPointer, const void *pointer, unsigned int size);
int hasRepeatedChar(char *input, int index);
int checkSeparatorOperator(char *input, int index, char lastSeparator);
int findFirstCharacter(char *input, int *index);
void printSyntaxError(ShellData *shell_data, char *input, int index, int isLogicalAnd);
int checkSyntaxError(ShellData *shell_data, char *input);
int customAtoi(char *string);
void checkEnvironmentVariable(VariableNode **head, char *input, ShellData *shell_data);
int checkVariables(VariableNode **head, char *input, char *start, ShellData *shell_data);
char *replaceInputWithVariables(VariableNode **head, char *input, char *newInput, int newLength);
char *replaceVariables(char *input, ShellData *shell_data);
char *concatenateStrings(char *destination, const char *source);
char *copyString(char *destination, char *source);
int compareStrings(char *string1, char *string2);
char *findCharacter(char *string, char character);
int findStringLength(char *string, const char *delimiters);
char *customStrtok(char *string, const char *delimiters);
int isStringNumeric(const char *string);
int runShell(ShellData *shell_data);
int (*getBuiltinCommand(char *command))(ShellData *);
int compareEnvironmentVariableName(const char *envVariable, const char *name);
char *getEnvironmentVariable(const char *name, char **environment);
int executeEnvCommand(ShellData *shell_data);
char *copyEnvironmentVariableInfo(char *name, char *value);
void setEnvironmentVariable(char *name, char *value, ShellData *shell_data);
int executeSetenvCommand(ShellData *shell_data);
int executeUnsetenvCommand(ShellData *shell_data);
int changeDirectory(ShellData *shell_data);
int exitShell(ShellData *shell_data);
int displayHelp(ShellData *shell_data);
char **customReallocatePointerArray(char **pointer, unsigned int old_size, unsigned int new_size);
void changeDirectoryDot(ShellData *shell_data);
void changeDirectoryTo(ShellData *shell_data);
void changeDirectoryPrevious(ShellData *shell_data);
void changeDirectoryToHome(ShellData *shell_data);
void reverseString(char *string);
int isCurrentDirectory(char *path, int *index);
char *findExecutablePath(char *command, char **environment);
int isExecutable(ShellData *shell_data);
int checkErrorCommand(char *directory, ShellData *shell_data);
int executeCommand(ShellData *shell_data);
int getError(ShellData *shell_data, int exitValue);

#endif /* HSH_H */

