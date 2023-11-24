#include "main.h"

/**
 * *_strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: a pointer to resulting string
 */

char *_strcat(char *dest, char *src)
{
	int i, f;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (f = 0; src[f] != '\0'; f++)
	{
		dest[i] = src[f];
		i++;
	}
	return (dest);
}
