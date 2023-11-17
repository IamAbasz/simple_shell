#include "hsh.h"

/**
 * appendCommandLine - adds a command line at the end
 * of a line_list.
 * @listHead: pointer head of the linked list.
 * @commandLine: command line to be added.
 * Return: address of the head.
 */
line_list *appendCommandLine(line_list **listHead, char *commandLine)
{
    line_list *newNode, *tempNode;

    newNode = malloc(sizeof(line_list));
    if (newNode == NULL)
        return (NULL);

    newNode->line = commandLine;
    newNode->next = NULL;
    tempNode = *listHead;

    if (tempNode == NULL)
    {
        *listHead = newNode;
    }
    else
    {
	    while (tempNode->next != NULL)
            tempNode = tempNode->next;
	    tempNode->next = newNode;
    }

    return *listHead;
}

