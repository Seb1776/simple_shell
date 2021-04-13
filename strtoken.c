#include "shell.h"
/**
 * strtok_line - This function divides a string of characters into words
 * @Linea:This parameter receives a string
 * Return:char
 */
char **strtok_line(char *Linea)
{
	char *token = NULL, **tokens = NULL, *separador = NULL;
	int count = 0, T_Linea = 0;

	while (Linea[T_Linea] != '\0')
	{
		T_Linea++;
	}
	tokens = malloc(T_Linea * sizeof(char *));
	if (tokens == NULL)
		perror("Error al alocar Token");
	separador = " \n";
	token = strtok(Linea, separador);
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		if (count >= T_Linea)
		{
			T_Linea += T_Linea;
			tokens = realloc(tokens, T_Linea * sizeof(char *));
			if (tokens == NULL)
				perror("Alocation Error");
		}
		token = strtok(NULL, separador);
	}
	tokens[count] = NULL;
	return (tokens);
}
