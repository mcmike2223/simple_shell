#ifndef _SHELL_H
#define _SHELL_H

#define BUFFSIZE 1024

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * serverEnv_s - environment variable
 * @PathName: environment name 
 * @widepath: global path
 * @next: points to the next node
 */

typedef struct serverEnv_s
{
char *pathName;
char *value;
char *globPath;
struct serverEnv_s *next;
} serverEnv_t;

/**
 * server_s - stores data variable
 * @cmdName: command name
 * @cmdList: command list
 * @argument: argument's arrays
 * @buff: buffer
 */

typedef struct server_s
{
char *cmdName;
char **cmdList;
char *pgName;
char **history;
char *buff;
char **argument;
serverEnv_t *env;
} server_t;

/**
 * Error - a structure for error message
 * @input: error input
 * @errorMessage: pointer to error messange
 */

typedef struct Error
{
int input;
char *errorMessage;
} Error_t;

/**
 * convert_s - convert a structure to a function
 * @commandName: input string
 * @function: pointer to a function
 */
typedef struct convert_s
{

char *cmdName;
void (*func)(server_t *);

} convert_t;

void print_prompt(void);
int _write(char *ptrstr);
int _putchar(char c);
int main(int argc __attribute__((unused)), char **argv);
void _getline(server_t *strucptr);
void (*getFunc(char *cmd))(server_t *);
void _execve(server_t *ptrData);

void *_calloc(unsigned int n, unsigned int size);
char *_memset(char *str, char c, unsigned int n_Byte);
char *_memcpy(char *dest, char *src, unsigned int size);
void *_realloc(void *ptr, unsigned int size, unsigned int n); 
serverEnv_t *_AddNodeEnd(serverEnv_t **HeadNode, char *globvalue);

void _Envserver(server_t *ptr);
serverEnv_t *_CreateNode(char *glob);
serverEnv_t *_LastNode(serverEnv_t *Node);
server_t *_countvalue(char **str);
int _Arr(char c, char *array);
int wordNum(char *str, char *aps);
char **_strtow(char *str, char *ap, char *sep);
int _checker(char c, char *E_sep);
int _checksep(char c, char *sep);

char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strconcat(char *Str1, char *Str2);

void _printEnviron(serverEnv_t *_Env);
void _Environ(server_t *ptr);
serverEnv_t *_getenv(serverEnv_t *ptrEnv, char *ptrName);
char *_EnvName(char *ptrvar);
char *EnvValue(char *ptrvar);
void _setEnviron(serverEnv_t *ptrEnv, char *ptrName, char *ptrV, int ptrOW);
void _cDir(server_t *ptrData);
void _cDHome(server_t *chptr, char *ptrcd);
void _cD_prev(server_t *ptrD, char *ptrCurDir);
void _RandomDir(server_t *varptr, char *curDir);
char *_genWord(char *Cptr, int abc, int len);
void _Word(char *ptrW, int *ptrI, char **Arr);
char *_cleanString(char *prmString);
void _Error(server_t *ptrData, int m);

void freeServerData(server_t *ptrData);
void freeArgument(char **ptr);
void freeList(serverEnv_t *ptrHeadNode);

void _help(server_t *ptrData);
void _exits(server_t *ptrData);
int _listEnvLen(serverEnv_t *prmHead);
void _unsetEnvironment(server_t *ptrserv);
void _unsetEnviron(server_t *ptrserv, char *ptrName);
int _delete(serverEnv_t *ptrH, char *ptrN);
serverEnv_t *_IndexNode(
	serverEnv_t *prmHead,
	unsigned int prmIndex
);
int _isNumber(char *s);
char *_itoa(int ptrNum);
int _isdigit(char ptrC);
int _numLen(int Num);
int _atoi(char *ptrstr);

int _EnvIndex(serverEnv_t *prmHead, char *prmName);
char *_genGlobal(char *ptrName, char *ptrV);
char *_absolute(server_t *ptrData);
char **_parse(server_t *ptrData);
char *_genAbs(char *ptrPath, char *ptrCmdName);

void _changedirectoryHelp(void);
void _envHelp(void);
void _exitHelp(void);
void _helpHelp(void);
void _defaultHelp(char *ptrCmd);
void _setEnvironment(server_t *ptrData);

#endif/*SHELL_H*/