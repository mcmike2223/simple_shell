#include "shell.h"

void _Error(server_t *ptrData, int m)
{
	
int i = 0;

Error_t errors[] = {
{00, "Error unknown"},
{100, "Error reading from Prompt - Zero tokens"},
{101, "No such file or directory"},
{102, "FATAL ERROR: UNABLE TO CREATE CHILD PROCESS"},
{103, "command not found"},
{104, "FATAL ERROR: NO MEMORY AVAILABLE."},
{105, "FATAL ERROR: UNABLE TO CREATE CMD LIST"},
{106, "Illegal number"},
{999, ""} /* Error Array end condition*/
};

_write(ptrData->pgName);
_write(": ");
_write("1");
_write(": ");
_write(ptrData->cmdName);
_write(": ");
while (i < 9)
{
if (m == (errors + i)->input)
{
_write((errors + i)->errorMessage);
_write(": ");
_write(ptrData->argument[1]);
}
i++;
}
_write("\n");
}

/**
 * _listEnvLen - length of a linked list
 *
 * @prmHead: first node
 *
 * Return: length
 */
int _listEnvLen(serverEnv_t *prmHead)
{
	if (prmHead == NULL)
		return (0);
	if (prmHead->next == NULL)
		return (1);
	else
		return (_listEnvLen(prmHead->next) + 1);
}

/**
 * _genGlobal - generate a global environment variable
 *                      from name and value
 * @ptrName: environment name
 * @ptrV: environment value
 *
 * Return: global environment variable
 */
char *_genGlobal(char *ptrName, char *ptrV)
{
	char *tmp, *global;

	global = "";
	global = _strconcat(global, ptrName);
	tmp = _strconcat(global, "=");
	free(global);
	global = _strconcat(tmp, ptrV);
	free(tmp);

	return (global);
}

/**
 * _isdigit - test if a character is a number
 *
 * @prmChar: char
 *
 * Return: return 1 if true
 */
int _isdigit(char ptrC)
{
	return (ptrC >= '0' && ptrC <= '9');
}

/**
 * _numLen - length of a number
 * @Num: number
 * Return: length of the number
 */

int _numLen(int Num)
{
	int i = 0, num1;

	if (Num == 0)
		return (1);

	num1 = Num;

	if (num1 < 0)
	{
		num1 *= -1;
		i++;	/* for the sign char */
	}

	while (num1)
	{
		num1 /= 10;
		i++;
	}

	return (i);
}
