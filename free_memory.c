#include "shell.h"

/**
 * freeServerData - free all pointers 
 * @ptrData: pointer to data stored
 */

void freeServerData(server_t *ptrData)
{
if (ptrData == NULL)
return;

if (ptrData->argument != NULL)
freeArgument(ptrData->argument);
ptrData->argument = NULL;

if (ptrData->buff != NULL && ptrData->cmdName !=  NULL)
free(ptrData->buff);
ptrData->buff = NULL;
free(ptrData->cmdName);
ptrData->cmdName = NULL;

if (ptrData->cmdList != NULL && ptrData->history != NULL)
freeArgument(ptrData->cmdList);
ptrData->cmdList = NULL;
freeArgument(ptrData->history);
ptrData->history = NULL;

}

/**
 * freeArgument - free the memory of a double pointer
 * @ptr: double pointer
 */

void freeArgument(char **ptr)
{
int i;

if (ptr == NULL)
return;

for (i = 0; ptr[i] != NULL; i++)
{
free(ptr[i]);
ptr[i] = NULL;
}
free(ptr);
}

void freeList(serverEnv_t *ptrHeadNode)
{
if (ptrHeadNode == NULL)
return;

freeList(ptrHeadNode->next);
free(ptrHeadNode->pathName);
ptrHeadNode->pathName = NULL;
free(ptrHeadNode->value);
ptrHeadNode->value = NULL;
free(ptrHeadNode->globPath);
ptrHeadNode->globPath = NULL;
free(ptrHeadNode);
}


/**
 * _absolute - return absolute path of a command
 *@ptrData: app data structure
 *
 * Return: absolute path
 */
char *_absolute(server_t *ptrData)
{
	char **pList, *abs;
	struct stat st;
	int iloop = 0;

	if (
		ptrData->cmdName[0] == '.' &&
		ptrData->cmdName[1] == '/' &&
		stat(ptrData->cmdName, &st) == 0
	)
		return (ptrData->cmdName);

	pList = _parse(ptrData);

	if (pList == NULL)
		return (NULL);

	while (pList[iloop] != NULL)
	{
		abs = _genAbs(pList[iloop], ptrData->cmdName);

	
		if (stat(abs, &st) == 0)
		{
			freeArgument(pList);
			return (abs);
		}
		free(abs);
		iloop++;
	}
	freeArgument(pList);

	
	if (stat(ptrData->cmdName, &st) == 0)
	{
		return (ptrData->cmdName);
	}
	else
		_Error(ptrData, 101);

	return (NULL);
}
