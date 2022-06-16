#include "shell.h"
/**
 * _setEnviron - set environment value
 * @ptrEnv: environment linked list
 * @ptrName: environment name
 * @ptrV: environment value
 * @ptrOW: overwrite
 */

void _setEnviron(serverEnv_t *ptrEnv, char *ptrName, char *ptrV, int ptrOW)
{
serverEnv_t *e_node;
char *tmp;

if (ptrName == NULL || ptrV == NULL)
return;

e_node = _getenv(ptrEnv, ptrName);

if (e_node == NULL)
{tmp = _genGlobal(ptrName, ptrV);
_AddNodeEnd(&ptrEnv, tmp);
free(tmp);
}
else if (ptrOW == 1)
{
free(e_node->value);
e_node->value = _strdup(ptrV);
}
}

/**
 * _cDir - change current directory
 * @ptrData: data structure
 */

void _cDir(server_t *ptrData)
{
	char cD[500];

	getcwd(cD, 500);

	if (ptrData == NULL)
		return;

	if (
		!ptrData->argument[1] ||
		_strcmp(ptrData->argument[1], "~") == 0 ||
		_strcmp(ptrData->argument[1], "~/") == 0
	)
		_cDHome(ptrData, cD);
	else if (_strcmp(ptrData->argument[1], "-") == 0)
		_cD_prev(ptrData, cD);
	else
		_RandomDir(ptrData, cD);
}

/**
 * _cDHome - change to home directory
 * @chptr - struct pointer
 * @ptrCd - current directory
 */

void _cDHome(server_t *chptr, char *ptrcd)
{
serverEnv_t *newcdir;

newcdir = _getenv(chptr->env, "Home");

if (access(newcdir->value, R_OK | W_OK) == 0)
{
chdir(newcdir->value);
_setEnviron(chptr->env, "OLDPWD", ptrcd, 1);
}
else
{
perror(newcdir->value);
}
}

/**
 * _cD_prev - change to previous directory
 *
 * @ptrD: data structure
 * @ptrCurDir: current directory path
 */
void _cD_prev(server_t *ptrD, char *ptrCurDir)
{
serverEnv_t *Directory;

Directory = _getenv(ptrD->env, "OLDPWD");

if (access(Directory->value, R_OK | W_OK) == 0)
{
chdir(Directory->value);
_setEnviron(ptrD->env, "OLDPWD", ptrCurDir, 1);
}
else
{
perror(Directory->value);
}
}

/**
 * _RandomDir - change to any directory
 *
 * @varptr: data structure
 * @curDir: current directory path
 */
void _RandomDir(server_t *varptr, char *curDir)
{
char *Directory;

Directory = varptr->argument[1];

if (access(Directory, R_OK | W_OK) == 0)
{
chdir(Directory);
_setEnviron(varptr->env, "OLDPWD", curDir, 1);
}
else
perror(Directory);
}
