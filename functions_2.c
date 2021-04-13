#include "shell.h"

/**
 * builtin_manager - Verify built in functions
 *
 * @cmd: Command to compare
 *
 * Return: on success, 1; on failure, 0
 */

int builtin_manager(char *cmd)
{
	int i = 0;

	builtin_funcs funcs_builtin[] = {
		{"exit", invoke_sh_exit},
		{"env", invoke_sh_printenv},
		{NULL, NULL}
	};

	if (check_for_empty(cmd) == 0)
		return (1);

	while (funcs_builtin[i].nam != NULL)
	{
		if (_strcmp(cmd, funcs_builtin[i].nam, _strlen(cmd) - 1) == 0)
		{
			funcs_builtin[i].func(cmd);
			return (1);
		}

		i++;
	}

	return (0);
}

/**
 * invoke_sh_printenv - Shows the current environment
 *
 * @cmd: Input from the user
 *
 * Return: on success, 1; on failure, 0
 */

int invoke_sh_printenv(char *cmd)
{
	int i, j;

	if (!cmd)
		return (0);

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);

		_putchar('\n');
	}

	return (1);
}

/**
 * _strcmp - Compares to given strings
 *
 * @frm: First string
 * @dst: Second string
 * @size: chars to compare.
 *
 * Return: If strings are different, -1; Otherwise, 0
 */

int _strcmp(char *frm, const char *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		if (frm[i] != dst[i])
			return (-1);

	return (0);
}

/**
* _strlen - Length of array
*
* @s: string
*
* Return: Length of array
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _puts - Prints a string
 *
 * @str: string
 *
 * Return: void
 */
void _puts(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		_puterror(str[i]);
		i++;
	}
}

/**
 * _atoi - Converts an int into a string to print it
 *
 * @i: Int to print (get it?)
 *
 * Return: void
 */
void _atoi(int i)
{
	int dig = 0, cpi = i, pot = 1;

	while (i > 0)
	{
		i = i / 10;
		dig++;
	}

	while (dig > 1)
	{
		pot *= 10;
		dig--;
	}

	for (; pot > 0; pot /= 10)
	{
		_puterror((cpi / (pot)) + 48);
		cpi %= pot;
	}
}

/**
 * _puterror - Prints a char to stderr
 *
 * @c: Char to print
 *
 * Return: On success, 1; On failure, -1
 */
int _puterror(char c)
{
	return (write(2, &c, 1));
}

/**
 * check_for_empty - Checks if a given str is empty
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
