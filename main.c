#include "shell.h"

/**
 * main - Main function, initializes Shell
 *
 * @argc: Amount of Arguments
 * @argv: Arguments
 *
 * Return: current state
 */
int main(void)
{
	int cmd;
	char *dspl = "$ ", *empty = NULL, **token = NULL;
	size_t n;



	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, dspl, strlen(dspl));

		cmd = getline(&empty, &n, stdin);
		token = strtok_line(empty);
		hsh_execute(token);
		if (cmd == EOF)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			invoke_sh_exit(empty);
		}
		if (cmd != -1)
		{
			builtin_manager(empty);
		}
	}
}
