#include "shell.h"

/**
 * _calloc - allocates memory for ana array
 * @n: number of a character
 * @size: size of memory
 */

void *_calloc(unsigned int n, unsigned int size)
{
void *ptr;

if (n == 0 || size == 0)
return (NULL);

ptr = malloc(size * n);

if (ptr == NULL)
return (NULL);

ptr = _memset(ptr, 0, n * size);

return (ptr);
}

/**
 * memset - fills the memory area pointed to by the
 * constant byte
 * @str: memory area pointer
 * @ c: constant
 * @n_Byte: No of byte to fill
 *
 * Return: number of bytes to the memory area
 */

char *_memset(char *str, char c, unsigned int n_Byte)
{
unsigned int i = 0;

while (i < n_Byte)
{
str[i] = c;
i++;
}
return (str);
}

/**
 * _realloc - reallocates memory
 * @ptr: source pointer
 * @size: pointer size in
 * @n: pointer size out
 *
 * Return: reallocated memory pointer
 */

void *_realloc(void *ptr, unsigned int size, unsigned int n)
{
void *size_ptr = ptr;
if (ptr == NULL)
return (malloc(n));

if (n == size)
return(ptr);

if (n == 0)
{
free(ptr);
return (NULL);
}

size_ptr = malloc(n);

if (size_ptr == NULL)
return (NULL);

size_ptr = _memcpy(size_ptr, ptr, size);
free(ptr);

return (size_ptr);
}

/**
 * _memcpy - copies the size of memory from
 * the src memory area to dest memory area
 * @dest: destination memory area
 * @src: source memory area
 *
 * Return: dest with the size of memory in bytes
 */

char *_memcpy(char *dest, char *src, unsigned int size)
{
unsigned int i = 0;

while(i < size)
{
dest[i] = src[i];
i++;
}
return (dest);
}
