#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @t: the pointer to the memory area
 * @b: the byte to fill *t with
 * @n: the amount of bytes to be filled
 * Return: a pointer to the memory area t
 */
char *_memset(char *t, char b, unsigned int n)
{
	unsigned int l;

	for (l = 0; l < n; l++)
	{
		t[l] = b;
	}
	return (t);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **g = pp;

	if (!pp)
	{
		return;
	}
	while (*pp)
	{
		free(*pp++);
	}
	free(g);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the old block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *z;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}

	z = malloc(new_size);
	if (!z)
	{
		return (NULL);
	}

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		z[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (z);
}
