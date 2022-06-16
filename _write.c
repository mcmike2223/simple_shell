#include "shell.h"

/**
 * _write - prints a character to stdout
 * @c: a character to print
 * 
 * Return: numebr of printed characters
 */

int _putchar(char c)
{
return(write(STDIN_FILENO, &c, 1));
}

/**
 * _printstr - prints all characters from string to stdout.
 * @c: characters in string form
 *
 * Return: No of printed characters
 */

int _write(char *ptrstr)
{
int i = 0, overall = 0;

while (ptrstr[i])
{
overall += _putchar(ptrstr[i]);
i++;
}
return (overall);
}
 