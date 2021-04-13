#include "shell.h"

/**
 * invoke_sh_exit - Exit current shell
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

	if (pid > 0)
		wait(&st);

	else
	{
		perror("An error ocurried");
		global_st = EXIT_FAILURE;
	}
}

/**
 * error_manager - Manages error type "A" & "B"
 *
 * @cmd: Given command
 * @hst: History of cmds
 *
 * Return: void
 */
void error_manager(char *cmd, int hst)
{
	int i;

	i = _strlen(cmd);

	cmd[i] = '\0';

	if (errno == ENOENT)
		hsh_error_type_a(cmd, hst);

	else if (errno == EACCES)
		hsh_error_type_b(cmd, hst);

	else
		global_st = 2;
}

/**
 * hsh_error_type_a - Shows when there's no file/directory
 *
 * @cmd: Command
 * @hst: History of cmds
 *
 * Return: void
 */

void hsh_error_type_a(char *cmd, int hst)
{
	char *dots = ": ";
	char *err = "No such file or directory\n";

	_puts(hsh_call);
	_puts(dots);
	_atoi(hst);
	_puts(dots);
	_puts(cmd);
	_puts(dots);
	_puts(err);

	global_st = 127;
}

/**
 * hsh_error_type_b - Shows when there's not enough permission
 *
 * @cmd: Given command
 * @hst: History of cmds
 *
 * Return: void
 */

void hsh_error_type_b(char *cmd, int hst)
{
	char *dots = ": ";
	char *err = "not enough permissions\n";

	_puts(hsh_call);
	_puts(dots);
	_atoi(hst);
	_puts(dots);
	_puts(cmd);
	_puts(dots);
	_puts(err);

	global_st = 126;
}
