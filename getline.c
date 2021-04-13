#include "shell.h"
/**
 * read_Getline - This function obtains the entered characters by keyboard
 * Return:char
 */
char *read_Getline(void)
{
	size_t  t = 0, c_readed = 0;
	char *linea;

	linea = (char *)malloc(t * sizeof(char));
	if (linea == NULL)
		printf("No se pudo alojar memoria");

	c_readed = getline(&linea, &t, stdin);
	return (linea);
}
