#include "main.h"

/**
 * freeme - frees a pointer array
 * @ptr: pointer to the array
 * Return: void
*/

void freeme(char **ptr)
{
	int i;

	if (ptr == NULL)
		return;
	for (i = 0; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
}
