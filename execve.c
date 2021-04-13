#include "shell.h"
/**
 * execute - this function uses execve to run a process
 * @tokens:This parameter receives the words that were divided by strtok
 * Return:int
 */
int execute(char **tokens)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
			perror("Error proceso hijo");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Erorr al crear el proceso");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
