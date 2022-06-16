#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @src: source pointer
 * @dest: destination pointer
 *
 * Return: concatenated string.
 */

char *_strcat(char *dest, char *src)
{
int len = 0, i, j;

i = _strlen(dest);
j = _strlen(src);

while(len < j)
{
dest[i + len] = src[len];
len++;
}
return (dest);
}

/**
 * _strcmp - compare two strings
 * @str1: string pointer to compare
 * @str2: another string to compare
 * 
 * Return: compare strings
 */

int _strcmp(char *str1, char *str2)
{
int len;

for (len = 0; str1[len] != '\0'; len++)
{
if (str1[len] - str2[len] != 0)
return (str1[len] - str2[len]);
}
return (0);
}

/**
 * _strlen - calculates the number of the string
 * @str: the string
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
if (str == NULL || *str == '\0')
return (0);

return(_strlen(str + 1) + 1);
}

/**
 * _strdup - returns a pointer to a null-terminated byte string
 * in the newly allocated space
 * @str: a string ton duplicate
 *
 * Return: returns a pointer to a null-terminated byte string
 */

char *_strdup(char *Dupstr)
{
int i;
char *ptrstr;

if (Dupstr == NULL)
return (NULL);

ptrstr = malloc(sizeof(char) * (_strlen(Dupstr) + 1));
if (ptrstr == NULL)
return (NULL);

for (i = 0; i < _strlen(Dupstr) + 1; i++)
ptrstr[i] = Dupstr[i];

return (ptrstr);
}

/**
 * my_strcpy - it copies a string from source to the dest
 * including the terminating null byte 
 * @dest: destination pointer of char
 * @src: source pointer of char
 *
 * Return: a character pointer with the copied string
 */

char *_strcpy(char *dest, char *src)
{
int i = 0, s = _strlen(src);

while(i < s)
{
dest[i] = src[i];
i++;
}
dest[s] = '\0';

return (dest);
}
