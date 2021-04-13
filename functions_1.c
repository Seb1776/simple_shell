#include "shell.h"

/**
 * hsh_shell_exit - Exit current shell
 *
 * @cmd: Input from the user
 *
 * Return: exit success
 */

int invoke_sh_exit(char *cmd)
{
	free(cmd);
	exit(global_st);
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
