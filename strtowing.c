#include "shell.h"

/**
 * _Arr - looks for a character in an array
 * @c: a character
 * @array: ana array of characters to be searched
 *
 * Return: a char on success.
 */

int _Arr(char c, char *array)
{
int i;
if (array == NULL)
return (0);

for (i = 0; array[i] != '\0'; i++)
if (array[i] == c)
return (1);

return (0);
}

/**
 * wordNum - calculates the num of a word
 * @str: pointer to a charactor
 * @aps: separator
 *
 * Return: num of a word calculated
 */

int wordNum(char *str, char *aps)
{
int i, c;

while (str[i] != '\0')
{
if ((_Arr(str[i], aps) != 1 || str[i] != '\0') && (_Arr(str[i + 1], aps) == 1 || str[i] == '\0'))
i++;
c++;
}
return (c);
}

/**
 * _strtow - function that splits a string into words
 * @str: a pointer to character
 * @ap: separator
 * @esp: escape separator
 *
 * Return: an array of words
 */

char **_strtow(char *str, char *ap, char *sep)
{
int i, j, size = 0, num = 0, n = 0;
char *w1 = NULL, **w2 = NULL, c;

if (str == NULL)
return (NULL);

n = _strlen(str);
num = wordNum(str, ap);

if (str == NULL || !str || num == 0)
return (NULL);

w2 = _calloc(sizeof(char *), (num + 1));

if (w2 == NULL)
return (NULL);
for (i = 0; i <= n && j < num; i++)
{
c = str[i];
if (_checker(c, sep))
break;
if (!_checksep(c, ap))
size++;
else if (size > 0)
{
w1 = _genWord(str, i - size,  size);
_Word(w1, &j, w2);
size = 0;
}
}
w2[j] = NULL;
 
return (w2);                                                                                                                
}

/**
 * _checker - checks if a char is equal to escape separator
 * @c: a charactor to check
 * @E_sep: escape separator
 *
 * Return: 1 on success, 0 on failure
 */

int _checker(char c, char *E_sep)
{
if (E_sep == NULL)
return (0);

return (_Arr(c, E_sep));
}

/**
 * check if a char is equal to a separator or EOF char
 * @c: a charactor to check
 * @sep: separator
 *
 * Return: 1 on success, 0 on failure
 */

int _checksep(char c, char *sep)
{
if (sep == NULL)
return (0);

return (_Arr(c, sep) == 1 || c == '\0');
}
