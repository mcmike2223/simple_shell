#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
server_t *serverptr = NULL;
int i;
void (*func)(server_t *);

serverptr = _countvalue(argv);

do
{
/* code */
print_prompt();

_getline(serverptr);

serverptr->history = _strtow(serverptr->buff, ";\n", "#");

if (serverptr->history == NULL)
{
freeServerData(serverptr);
free(serverptr);
continue;
}

for (i = 0; serverptr->history[i] != NULL; i++)
{
serverptr->argument = _strtow(serverptr->history[i], "\n", "#");

if (serverptr->argument == NULL)
{
freeServerData(serverptr);
freeList(serverptr->env);
serverptr->env = NULL;
free(serverptr);
serverptr = NULL;
break;
}

serverptr->cmdName = strdup(serverptr->argument[0]);

if (serverptr->cmdName != NULL)
{
func = getFunc(serverptr->cmdName);

if (func != NULL)
func(serverptr);
else
_execve(serverptr);
}
freeArgument(serverptr->argument);
serverptr->argument = NULL;
free(serverptr->cmdName);
serverptr->cmdName = NULL;
}
freeServerData(serverptr);
} while (1);

return (EXIT_SUCCESS);
}

/**
 * _getline - return a command line by user
 * @strucptr: a structure pointer
 */
 
void _getline(server_t *strucptr)
{
int i = 0, read_line, size = BUFFSIZE;
char s = '\0';

strucptr->buff = _calloc(sizeof(char), BUFFSIZE);

while (s != '\n' && s != EOF)
{
read_line = read(STDIN_FILENO, &s, 1);

if (read_line == 0)
{
_putchar('\n');
if (strucptr->env != NULL)
freeList(strucptr->env);
strucptr->env = NULL;
freeServerData(strucptr);
free(strucptr);
exit(EXIT_SUCCESS);
}
if (i >= size - 1)
{
strucptr->buff = _realloc(strucptr->buff, size, sizeof(char) * (i + 2));
size = i + 2;
}
strucptr->buff[i] = s;
i++;
}
strucptr->buff[i] = '\0';
}

/**
 * _getCustomFunction - check custom command
 *
 * @prmCommand: command
 *
 * Return: pointer function
 */
void (*getFunc(char *ptrCmd))(server_t *)
{
	int i = 0;

	convert_t fp[] = {
		{"cd", _cDir},
		{"env", _Environ},
		{"setenv", _setEnvironment},
		{"unsetenv", _unsetEnvironment},
		{"exit", _exits},
		{"help", _help}
	};

	while (i < 6)
	{
		if (_strcmp(ptrCmd, (fp + i)->cmdName) == 0)
			return ((fp + i)->func);
		i++;
	}

	return (NULL);
}

/**
 * _execve - execute commands
 * @ptrData: an array of data structure
 */

void _execve(server_t *ptrData)
{
pid_t cpid;
char *cmd;
int status;

if (ptrData->cmdName == NULL)
return;

cmd = _absolute(ptrData);

if (cmd != NULL)
{
if (ptrData->cmdName != cmd)
free(ptrData->cmdName);
ptrData->cmdName = cmd;
}
else
{
return;
}

cpid = fork();

if (cpid == 0)
{
if (execve(ptrData->cmdName, ptrData->argument, NULL) == -1)
_Error(ptrData, 103);
return;
}
else if (cpid == -1)
{
_Error(ptrData, 102);
}
else
waitpid(cpid, &status, WUNTRACED);
}
