#include "shell.h"

/**
 * _strcmp - Compares to given strings
 *
 * @frm: First string
 * @dst: Second string
 * @size: chars to compare.
 *
 * Return: If strings are different, -1; Otherwise, 0
 */

int _strcmp(char *frm, const char *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		if (frm[i] != dst[i])
			return (-1);

	return (0);
}

/**
* _strdup - Duplicates a string
*
* @str: String to duplicate
*
* Return: On success, string; On falirue, NULL
*/

char *_strdup(char *str)
{
	unsigned int i = 0, j;
	char *s;

	if (str == NULL)
		return (NULL);

	while (str[i] != 0)
		i++;

	s = malloc(i + 1);

	if (s == NULL)
		return (NULL);

	for (j = 0; str[j] != 0; j++)
		s[j] = str[j];

	s[j] = '\0';
	return (s);
}

/**
* _strcat - Concatenates 2 given strings
*
* @str1: Frist string
* @str2: Second string
*
* Return: On success, concatenated string; On failure, NULL
*/

char *_strcat(char *str1, char *str2)
{
	unsigned int i, j, k, k1 = 0, k2 = 0;
	char *s;

	if (str1 != NULL)
	{
		while (str1[k1] != 0)
			k1++;
	}

	if (str2 != NULL)
	{
		while (str2[k2] != 0)
		k2++;
	}

	k = k1 + k2 + 2;
	s = malloc(sizeof(char) * k);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < k1; i++)
		s[i] = str1[i];

	s[i++] = '/';

	for (j = 0; j < k2; j++)
		s[i + j] = str2[j];

	s[i + j] = 0;

	return (s);
}
