#include "shell.h"

/**
 * _printEnviron - prints environ variables
 * @_Env: variable list
 */

void _printEnviron(serverEnv_t *_Env)
{
if (_Env == NULL)
return;

_write(_Env->pathName);
_write("=");
if (_Env->value != NULL)
_write(_Env->value);
_write("\n");
_printEnviron(_Env->next);
}

/**
 * _Environ - prints the environ variable
 *
 * @ptr: data structure
 */

void _Environ(server_t *ptr)
{
_printEnviron(ptr->env);
}

/**
 * _getenv - get environ variable
 * @ptrEnv: head node
 * @ptrName: variable name
 *
 * return: variable node
 */

serverEnv_t *_getenv(serverEnv_t *ptrEnv, char *ptrName)
{
if (ptrEnv == NULL)
return (NULL);

if (_strcmp(ptrEnv->pathName, ptrName) == 0)
return (ptrEnv);

return (_getenv(ptrEnv->next, ptrName));
}

/**
 * _EnvName - Returns the environ name
 * @ptrVar: Name
 *
 * Return: Environ name
 */

char *_EnvName(char *ptrvar)
{
char **tptr, *name;

tptr = _strtow(ptrvar, "=", NULL);

if (tptr == NULL)
return (NULL);

name = _strdup(tptr[0]);
freeArgument(tptr);
tptr = NULL;

return (name);
}

/**
 * _EnvValue - return environ value
 * @ptrVariable: name
 *
 * Return: environ value
 */

char *EnvValue(char *ptrvariable)
{
char **cptr, *name;

cptr = _strtow(ptrvariable, "=", NULL);

if (cptr == NULL)
return(NULL);

name = _strdup(cptr[1]);
freeArgument(cptr);
cptr = NULL;

return (name);
}
