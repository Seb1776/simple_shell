#include "shell.h"

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
 * hsh_shell_manage_path - Manage the PATH directories
 *
 * @cmd: Input from user
 *
 * Return: buffer/array
 */
char **hsh_shell_manage_path(char *cmd)
{
	int i;
	char *envpath = "PATH=", *cct, *pget, **pbuff, **arr;
	struct stat st;

	arr = write_to_buffer(cmd, " \n");

	if (arr[0][0] == '.' && arr[0][1] == '/')
		return (arr);

	pget = (hsh_shell_freshpath(_getenv(envpath)));

	if (pget)
	{
		pbuff = write_to_buffer(pget, ":\n");

		for (i = 0; pbuff[i]; i++)
		{
			cct = _strcat(pbuff[i], arr[0]);

			if (stat(cct, &st) == 0)
			{
				for (i = 0; pbuff[i]; i++)
					free(pbuff[i]);

				free(pbuff);
				free(pget);
				free(arr[0]);
				arr[0] = cct;
				return (arr);
			}
			free(cct);
		}

		for (i = 0; pbuff[i]; i++)
			free(pbuff[i]);
		free(pbuff);
	}

	free(pget);
	return (arr);
}
