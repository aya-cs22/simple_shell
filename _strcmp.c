#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string1
 * @s2: string2
 * Return: less than 0 if s1 is greater than s2
 *	0 if they are similar
 *	greater than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int i, flag;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return (s1[i] - s2[i]);
	return (0);
}
