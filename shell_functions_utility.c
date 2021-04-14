#include "shell.h"

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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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
