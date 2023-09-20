#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int t = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[t])
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int t = 0;

	if (!str)
		return;
	while (str[t] != '\0')
	{
		_putchar(str[t]);
		t++;
	}
}

/**
 * _putchar - writes the character d to stdout
 * @d: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char d)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(1, buf, t);
		t = 0;
	}
	if (d != BUF_FLUSH)
		buf[t++] = d;
	return (1);
}
