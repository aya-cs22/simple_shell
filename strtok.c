#include "main.h"

/**
 * tmp_strtok - tokenizes a string
 * @buffer: string to tokenize
 * Return: pointer to the first token
 * NULL on failure or EOF
*/

char **tmp_strtok(char *buffer)
{

	int j, i = 0;
	char *token, *bufcpy = strdup(buffer);
	char **ptrarr;

	token = strtok(bufcpy, " \t\n");
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " \t\n"); }
	free(bufcpy);
	ptrarr = malloc(sizeof(char *) * (i + 1));
	if (ptrarr == NULL)
	{
		perror("malloc ERROR:");
		free(buffer);
		free(ptrarr);
		exit(EXIT_FAILURE); }
	i = 0;
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		ptrarr[i] = strdup(token);
		if (ptrarr[i] == NULL)
		{
			perror("strdup ERROR:");
			free(ptrarr[i]);
			for (j = 0; j < i; j++)
				free(ptrarr[j]);
			free(ptrarr), free(buffer);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
		i++; }
	free(buffer), buffer = NULL;
	ptrarr[i] = NULL;
	return (ptrarr);
}
