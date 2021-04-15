#include "shell.h"

/**
 * hsh_execute - Execute a command
 *
 * @cmd: Commands to execute
 * @hst: History of commands
 * @txt: Given line
 *
 * Return: st
 */

void hsh_execute(char **cmd, int hst, char *txt)
{
	pid_t pid;
	int i = 0, st;

	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			error_manager(cmd[0], hst);
			free(txt);

			while (cmd[i])
			{
				free(cmd[i]);
				i++;
			}

			free(cmd);
			exit(global_st);
		}
	}


	else
	{
		wait(&st);
		kill(pid, SIGKILL);
	}
}

/**
 * hsh_shell_exit - Exit current shell
 *
 * @cmd: Input from the user
 *
 * Return: exit success
 */

int hsh_shell_exit(char *cmd)
{
	free(cmd);
	exit(global_st);
}

/**
 * hsh_shell_printenv - Shows the current environment
 *
 * @cmd: Input from the user
 *
 * Return: on success, 1; on failure, 0
 */

int hsh_shell_printenv(char *cmd)
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
		{"exit", hsh_shell_exit},
		{"env", hsh_shell_printenv},
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
