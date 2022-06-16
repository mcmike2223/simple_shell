#include "shell.h"

/**
 * _countvalue - initializes the structure
 * Return: structure's data
 */

server_t *_countvalue(char **str)
{
server_t *strucptr;
strucptr = malloc(sizeof(server_t) * 1);

if (strucptr == NULL)
return (NULL);

strucptr->cmdName = NULL;
strucptr->cmdList = NULL;
strucptr->pgName = (str[0] != NULL) ? str[0] : NULL;
strucptr->history = NULL;
strucptr->buff = NULL;
strucptr->argument = NULL;
strucptr->env = NULL;
_Envserver(strucptr);

return (strucptr);
}

/**
 * _Envserver - initializing env linked list
 * @ptr: structure's data
 */

void _Envserver(server_t *ptr)
{
int i;
serverEnv_t *new_node;

if (ptr == NULL)
return;

for (i = 0; environ[i] != NULL; i++)
{
new_node = _AddNodeEnd(&ptr->env, environ[i]);

if (new_node == NULL)
{
free(ptr->env);
ptr->env = NULL;
return;
}
}
}

/**
 * _AddNodeEnd - add a new node at the end
 * @HeadNode: head node pointer
 * @globvalue: global value
 *
 *Return: Last node
 */

serverEnv_t *_AddNodeEnd(serverEnv_t **HeadNode, char *globvalue)
{
serverEnv_t *NewNode, *LastNode;

if (HeadNode == NULL)
return (NULL);

NewNode = _CreateNode(globvalue);

if (NewNode == NULL)
return (NULL);

if (*HeadNode == NULL)
*HeadNode = NewNode;

else
{
LastNode = _LastNode(*HeadNode);

if (LastNode == NULL)
{
free(NewNode);
return (NULL);
}
LastNode->next = NewNode;
}
return (NewNode);
}

/**
 * _CreateNode - creates a new node 
 * @glob: glob value of the environment
 *
 * Return: new node
 */

serverEnv_t *_CreateNode(char *glob)
{
serverEnv_t *NewNode;

if (glob == NULL)
return (NULL);

NewNode = malloc(sizeof(serverEnv_t));

if (NewNode == NULL)
return (NULL);

NewNode->pathName = _EnvName(glob);
NewNode->value = EnvValue(glob);
NewNode->globPath = _strdup(glob);
NewNode->next = NULL;

return (NewNode);
}

/**
 * _lastNode - generates last node
 * @Node: the first node
 *
 * Return: last node
 */

serverEnv_t *_LastNode(serverEnv_t *Node)
{
serverEnv_t *HeadNode, *NextNode;

HeadNode = Node;

if (HeadNode == NULL)
return (NULL);

NextNode = HeadNode->next;

if (NextNode == NULL)
return (HeadNode);
else
return (_LastNode(NextNode));
}
