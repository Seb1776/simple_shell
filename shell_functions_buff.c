#include "shell.h"

/**
 * set_delimit - Checks for delimiters in a command
 *
 * @cmd: Command
 * @delims: delimiters
 *
 * Return: Amount of delims
 */
int set_delimit(char *cmd, char *delims)
{
	int i, k, l = 1;

	for (i = 0; cmd[i]; i++)
		for (k = 0; delims[k]; k++)
			if (delims[k] == cmd[i])
				l++;

	return (l);
}

/**
 * write_to_buffer - Creates a buffer
 *
 * @cmd: Given command
 * @delims: Delimiters
 *
 * Return: A buffer
 */

char **write_to_buffer(char *cmd, char *delims)
{
	char *tokz;
	char **buffer;
	int i, j = 0;

	i = set_delimit(cmd, delims);
	buffer = malloc(sizeof(char *) * (i + 1));
	tokz = strtok(cmd, delims);

	while (tokz)
	{
		buffer[j] = _strdup(tokz);
		tokz = strtok(NULL, delims);
		j++;
	}

	buffer[j] = NULL;
	return (buffer);
}

/**
 * hsh_shell_freshpath - Copies PATH, then checks for ":"
 *
 * @pathv: Current environment PAHT
 *
 * Return: Another string with a copy of PATH
 */
char *hsh_shell_freshpath(char *pathv)
{
	int i, j = 0;
	char *frshpath;

	if (pathv == NULL)
		return (NULL);

	frshpath = malloc(sizeof(char) * _strlen(pathv) - 4);

	if (pathv[5] == ':')
		frshpath[j++] = '.';

	for (i = 5; pathv[i]; j++, i++)
		frshpath[j] = pathv[i];

	frshpath[j] = '\0';

	return (frshpath);
}

/**
 * _getenv - get a enviroment variable if match.
 *
 * @nam: Name of environment variable
 *
 * Return: On success, environment; On failure, NULL
 */
char *_getenv(char *nam)
{
	int i, size = 0;

	while (nam[size])
		size++;

	if (environ == NULL)
		return (NULL);

	for (i = 0; environ[i]; i++)
		if ((_strcmp(environ[i], nam, size) == 0))
			if (_strlen(environ[i]) > 5)
				return (environ[i]);

	return (NULL);
}

/**
 * check_for_empty - Checks if a given str is empty at an instance.
 *
 * @str: Given string
 *
 * Return: if strings are different, -1; otherwise, 0
 */
int check_for_empty(char *str)
{
	int i = 0;

	if (str[0] == ' ' || str[0] == '\t')
		while (str[i] == ' ')
			i++;

	if (str[i] == '\n' && str[i + 1] == '\0')
		return (0);

	return (-1);
}
