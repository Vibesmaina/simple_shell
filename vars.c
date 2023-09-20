#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @z: address of current position in buf
 *
 * Return: 1 if chain delimiter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *z)
{
	size_t l = *z;

	if (buf[l] == '|' && buf[l + 1] == '|')
	{
		buf[l] = 0;
		l++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[l] == '&' && buf[l + 1] == '&')
	{
		buf[l] = 0;
		l++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[l] == ';') /* found end of this command */
	{
		buf[l] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*z = l;
	return (1);
}

/**
 * check_chain - checks if we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @z: address of current position in buf
 * @t: starting position in buf
 * @len: length of buf
 *
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *z, size_t t, size_t len)
{
	size_t l = *z;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[t] = 0;
			l = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[t] = 0;
			l = len;
		}
	}

	*z = l;
}

/**
 * replace_alias - replaces aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int g;
	list_t *node;
	char *g;

	for (g = 0; g < 10; g++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		g = _strchr(node->str, '=');
		if (!g)
			return (0);
		g = _strdup(g + 1);
		if (!g)
			return (0);
		info->argv[0] = g;
	}
	return (1);
}

/**
 * replace_vars - replaces variables in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int t = 0;
	list_t *node;

	for (t = 0; info->argv[t]; t++)
	{
		if (info->argv[t][0] != '$' || !info->argv[t][1])
			continue;

		if (!_strcmp(info->argv[t], "$?"))
		{
			replace_string(&(info->argv[t]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[t], "$$"))
		{
			replace_string(&(info->argv[t]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[t][1], '=');
		if (node)
		{
			replace_string(&(info->argv[t]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[t], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
