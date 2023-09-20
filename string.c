#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @t: the string length to check
 *
 * Return: integer length of string
 */
int _strlen(char *t)
{
	int g = 0;

	if (!t)
		return (0);

	while (*t++)
		g++;
	return (g);
}

/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @t: the first string
 * @g: the second string
 *
 * Return: negative if t < g, positive if t > g, zero if t == g
 */
int _strcmp(char *t, char *g)
{
	while (*t && *g)
	{
		if (*t != *g)
			return (*t - *g);
		t++;
		g++;
	}
	if (*t == *g)
		return (0);
	else
		return (*t < *g ? -1 : 1);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
