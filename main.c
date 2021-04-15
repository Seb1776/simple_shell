#include "shell.h"

/**
 * main - Main function, initializes Shell
 *
 * @ac: Amount of Arguments
 * @av: Arguments
 *
 * Return: current state
 */
int main(void)
{
	char *display = "$ ", *empty = NULL, **arr;
	int i, cmd, hst;
	size_t n = 0;
	struct stat st;

	global_st = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, display, _strlen(display));
		cmd = getline(&empty, &n, stdin);
		if (cmd == EOF)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			hsh_shell_exit(empty);
		}
		if (cmd != -1)
		{
			if (builtin_manager(empty) == 0)
			{
				arr = hsh_shell_manage_path(empty);
				if (stat(arr[0], &st) == 0)
					hsh_execute(arr, hst, empty);
				else
					error_manager(empty, hst);
				for (i = 0; arr[i]; i++)
					free(arr[i]);
				free(arr);
			}
		}
		else
			error_manager(empty, hst);
		hst++;
	}
	free(empty);
	return (global_st);
}
