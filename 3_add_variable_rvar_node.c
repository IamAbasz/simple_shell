#include "hsh.h"

/**

addRVarNode - Adds a variable at the end of a r_var list.

@head: Pointer to the head of the linked list.

@varLength: Length of the variable.

@value: Value of the variable.

@valueLength: Length of the value.

Return: Address of the head.
*/
r_var *addRVarNode(r_var **head, int varLength, char *value, int valueLength)
{
r_var *newNode, *temp;

newNode = malloc(sizeof(r_var));
if (newNode == NULL)
return (NULL);

newNode->len_var = varLength;
newNode->val = value;
newNode->len_val = valueLength;

newNode->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = newNode;
}
else
{
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}

return (*head);
}
