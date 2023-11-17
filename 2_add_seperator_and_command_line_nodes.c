#include "hsh.h"

/**

addNodes - Add separators and command lines to the lists.

@headCommandLines: Head of the command lines list.

@headSeparators: Head of the separator list.

@inputString: Input string.

Return: No return value.
*/
void addNodes(sep_list **headSeparators, line_list **headCommandLines, char *inputString)
{
int i;
char *commandLine;

 // Swap the first character in the input string
inputString = swapCharacters(inputString, 0);

    // Iterate through the characters in the input string
for (i = 0; inputString[i]; i++)
{
if (inputString[i] == ';')
addSeparatorNodeEnd(headSeparators, inputString[i]);

if (inputString[i] == '|' || inputString[i] == '&')
 {
 	addSeparatorNodeEnd(headSeparators, inputString[i]);
 	i++;
 }
}

commandLine = strtokString(inputString, ";|&");
do {
commandLine = swapCharacters(commandLine, 1);
addLineNodeEnd(headCommandLines, commandLine);
commandLine = strtokString(NULL, ";|&");
} while (commandLine != NULL);
}
