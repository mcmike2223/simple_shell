#include "shell.h"

/**
 * _strconcat - concatenates two strings.
 * @Str1: char pointer to concatenate
 * @Str2: char pointer to concatenate
 *
 * Return: char pointer concatenated
 */
char *_strconcat(char *Str1, char *Str2)
{
char *s;
int x, y, size;

if (Str1 == NULL)
Str1 = "\0";

if (Str2 == NULL)
Str2 = "\0";

size = _strlen(Str1) + _strlen(Str2);
s = malloc(sizeof(char) * (size + 1));

if (s == NULL)
return (NULL);

for (x = 0; Str1[x]; x++)
s[x] = Str1[x];

for (y = 0; Str2[y]; x++, y++)
s[x] = Str2[y];

s[x] = '\0';

return (s);
}

/**
 * _itoa - Convert an int to a string
 * @ptrNum: int to convert
 * Return: converted string
 */

char *_itoa(int ptrNum)
{
char *s;
int i;
long num;

num = ptrNum;
i = _numLen(num);
s = malloc(sizeof(char) * i + 1);

if (s == NULL)
{
return (NULL);
}

s[i] = '\0';

if (num == 0)
{
s = "0";
}
else if (num < 0)
{
s[0] = '-';
num *= -1;
}

while (num)
{
s[--i] = num % 10 + 48;
num /= 10;
}

return (s);
}

/**
 * _isNumber - check if string is a number
 *
 * @s: string to verify
 *
 * Return: 1 if string is a number.
 */
int _isNumber(char *s)
{
if (*s == '\0')
{
return (1);
}
if (!_isdigit(*s))
{
return (0);
}
else
{
return (_isNumber(s + 1));
}
}

/**
 * _atoi - convert a string to an integer.
 *
 * @ptrstr: char pointer
 *
 * Return: int
 */
int _atoi(char *ptrstr)
{
	char sign = 1, current;
	int size = _strlen(ptrstr), i;
	unsigned int num = 0;

	for (i = 0; i < size; i++)
	{
		current = ptrstr[i];

		if (_isdigit(current))
		{
			num *= 10;
			num += current - 48;
		}
		else if (current == '-')
			sign = -sign;
		else if (num > 0)
			break;
	}

	return (sign * num);
}

/**
 * _setEnvironment - set environment variable
 *
 * @prmData: data's structure
 */
void _setEnvironment(server_t *ptrData)
{
	if (ptrData == NULL)
		return;

	if (ptrData->argument == NULL)
		return;

	if (ptrData->argument[1] == NULL || ptrData->argument[2] == NULL)
		return;

	_setEnviron(ptrData->env, ptrData->argument[1], ptrData->argument[2], 1);
}
