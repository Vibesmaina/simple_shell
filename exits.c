#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int t, l;
	char *z = dest;

	t = 0;
	while (src[t] != '\0' && t < n - 1)
	{
		dest[t] = src[t];
		t++;
	}
	if (t < n)
	{
		l = t;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (z);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int t, l;
	char *z = dest;

	t = 0;
	l = 0;
	while (dest[t] != '\0')
		t++;
	while (src[l] != '\0' && l < n)
	{
		dest[t] = src[l];
		t++;
		l++;
	}
	if (l < n)
		dest[t] = '\0';
	return (z);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
