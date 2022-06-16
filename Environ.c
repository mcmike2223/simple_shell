#include "shell.h"

/**
 * _unsetEnvironment - unset environment variable
 *
 * @ptrserv: data's structure
 */
void _unsetEnvironment(server_t *ptrserv)
{
if (ptrserv == NULL)
return;
if (ptrserv->argument == NULL)
return;
if (ptrserv->argument[1] == NULL)
return;

_unsetEnviron(ptrserv, ptrserv->argument[1]);
}

/**
 * _unsetEnviron - unset environment variable
 *
 * @ptrserv: data structure
 * @ptrName: environment name
 */
void _unsetEnviron(server_t *ptrserv, char *ptrName)
{
_delete(ptrserv->env, ptrName);
}

/**
 * _delete - delete an environment variable
 * @ptrH first node
 * @ptrN: name
 *
 * Return: error code
 */

int _delete(serverEnv_t *ptrH, char *ptrN)
{
serverEnv_t *bef, *af, *c, *f;
unsigned int len, cI;

f = ptrH;
cI = _EnvIndex(ptrH, ptrN);

if (f == NULL)
return (-1);
len = _listEnvLen(f);

if (len == 0 || cI > (unsigned int) len - 1)
return (-1);

if (cI == 0)
{
ptrH = ptrH->next;
free(f);
return (1);
}

bef = _IndexNode(f, cI - 1);
if (cI == len - 1)
af = NULL;
else
af = _IndexNode(f, cI + 1);

c = _IndexNode(f, cI);
bef->next = af;
free(c->pathName);
c->pathName = NULL;
free(c->value);
c->value = NULL;
free(c->globPath);
c->globPath = NULL;
free(c);
c = NULL;

return (1);
}

/**
 * _IndexNode - the nth node of a listint_t linked list
 *
 * @prmHead: first element
 * @prmIndex: element's number
 *
 * Return: a node
 */
serverEnv_t *_IndexNode(
	serverEnv_t *prmHead,
	unsigned int prmIndex
) {
unsigned int cLoop = 0;

while (prmHead != NULL)
{
if (prmIndex == cLoop)
return (prmHead);
prmHead = prmHead->next;
cLoop++;
}

return (NULL);
}

/**
 * _EnvIndex - return index of an environment variable
 *
 * @prmHead: first node
 * @prmName: name
 *
 * Return: index
 */
int _EnvIndex(serverEnv_t *prmHead, char *prmName)
{
	if (prmHead == NULL || _strcmp(prmHead->pathName, prmName) == 0)
		return (0);
	else
		return (_EnvIndex(prmHead->next, prmName) + 1);
}
