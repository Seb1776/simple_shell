#include "shell.h"
/**
 * main - This function is the main function and execute other functions
 * Return:int
 */
int main(void)
{

	char *linea, **token;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		linea = read_Getline();
		token = strtok_line(linea);
		status = execute(token);
		free(linea);
		free(token);
		(void)status;
	}
	return (0);
}
