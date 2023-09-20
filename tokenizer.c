#include "shell.h"

/**
 * strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
	int t, q, l, p, numwords = 0;
	char **g;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (t = 0; str[t] != '\0'; t++)
		if (!is_delim(str[t], d) && (is_delim(str[t + 1], d) || !str[t + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	g = malloc((1 + numwords) * sizeof(char *));
	if (!g)
		return (NULL);
	for (t = 0, l = 0; l < numwords; l++)
	{
		while (is_delim(str[t], d))
			t++;
		q = 0;
		while (!is_delim(str[t + q], d) && str[t + q])
			q++;
		g[l] = malloc((q + 1) * sizeof(char));
		if (!g[l])
		{
			for (q = 0; q < l; q++)
				free(g[q]);
			free(g);
			return (NULL);
		}
		for (p = 0; p < q; p++)
			g[l][p] = str[t++];
		g[l][p] = 0;
	}
	g[l] = NULL;
	return (g);
}

/**
 * strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int t, q, l, p, numwords = 0;
	char **g;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (t = 0; str[t] != '\0'; t++)
		if ((str[t] != d && str[t + 1] == d) ||
			(str[t] != d && !str[t + 1]) || str[t + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	g = malloc((1 + numwords) * sizeof(char *));
	if (!g)
		return (NULL);
	for (t = 0, l = 0; l < numwords; l++)
	{
		while (str[t] == d && str[t] != d)
			t++;
		q = 0;
		while (str[t + q] != d && str[t + q] && str[t + q] != d)
			q++;
		g[l] = malloc((q + 1) * sizeof(char));
		if (!g[l])
		{
			for (q = 0; q < l; q++)
				free(g[q]);
			free(g);
			return (NULL);
		}
		for (p = 0; p < q; p++)
			g[l][p] = str[t++];
		g[l][p] = 0;
	}
	g[l] = NULL;
	return (g);
}
