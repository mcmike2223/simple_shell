#include "shell.h"

/**
 * _genWord - returns word
 * @Cptr: char pointer
 * @abc: start of the word
 * @len: length of the word
 *
 * Return: Word number
 */

char *_genWord(char *Cptr, int abc, int len)
{
char *x;
int i;

x = malloc(sizeof(char) * len + 1);

if (x == NULL)
return (NULL);

for (i = 0; i < (len); i++)
x[i] = Cptr[abc + i];

x[i] = '\0';

return (x);
}

/**
 * _Word - add a word to an array
 * @ptrW: word to add
 * @ptrI: current index
 * @Arr: array
 */

void _Word(char *ptrW, int *ptrI, char **Arr)
{
ptrW = _cleanString(ptrW);
Arr[*ptrI] = _strdup(ptrW);
free(ptrW);
*ptrI += 1;
}

/**
 * _cleanString - erase begin spaces and ending spaces from string
 *
 * @prmString: string to clean
 *
 * Return: clean string
 */
char *_cleanString(char *prmString)
{
	int iLoop = 0, NLoop = 0, size = 0;
	char *string;

	if (prmString == NULL)
		return (NULL);

	size = _strlen(prmString);

	while (_Arr(prmString[iLoop], " ") == 1)
		iLoop++;

	NLoop = size - 1;
	while (_Arr(prmString[NLoop], " ") == 1)
		NLoop--;
	NLoop = size - 1 - NLoop;

	string = _calloc(sizeof(char), size - iLoop - NLoop + 1);
	strncpy(string, (prmString + iLoop), size - iLoop - NLoop);
	string[size - iLoop - NLoop] = '\0';

	/**prmString = *string;*/
	prmString = _realloc(
		prmString,
		size,
		sizeof(char) * (size - iLoop - NLoop + 1)
	);
	_strcpy(prmString, string);
	prmString[size - iLoop - NLoop] = '\0';
	free(string);
	return (prmString);
}

/**
 * _help - manage command help
 *
 * @prmData: data structure
 */
void _help(server_t *ptrData)
{
if (ptrData == NULL)
return;
if (ptrData->cmdName == NULL)
return;
    if (
		ptrData->argument == NULL ||
		ptrData->argument[0] == NULL ||
		ptrData->argument[1] == NULL
	)
return;
if (_strcmp(ptrData->argument[1], "cd") == 0)
_changedirectoryHelp();
else if (_strcmp(ptrData->argument[1], "env") == 0)
_envHelp();
else if (_strcmp(ptrData->argument[1], "setenv") == 0)
return;
else if (_strcmp(ptrData->argument[1], "unsetenv") == 0)
return;
else if (_strcmp(ptrData->argument[1], "exit") == 0)
_exitHelp();
else if (_strcmp(ptrData->argument[1], "help") == 0)
_helpHelp();
else
_defaultHelp(ptrData->argument[1]);
}

/**
 * _exits - exit status
 *
 * @ptrData: data structure
 */
void _exits(server_t *ptrData)
{
int input = EXIT_SUCCESS;

if (ptrData == NULL)
return;

if (ptrData->argument != NULL)
input = _atoi(ptrData->argument[1]);

if (input < 0 || (ptrData->argument[1] != NULL && !_isNumber(ptrData->argument[1])))
{
_Error(ptrData, 106);
input = 2;
}

freeServerData(ptrData);
freeList(ptrData->env);
ptrData->env = NULL;
free(ptrData);
exit(input);
}
