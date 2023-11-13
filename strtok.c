#include "main.h"

/**
 * tmp_strtok - tokenizes a string
 * @buffer: string to tokenize
 * Return: pointer to the first token
 * NULL on failure or EOF
*/

char **tmp_strtok(char *buffer)
{
	int i = 0;
	char *token, *bufcpy = strdup(buffer);
	char **ptrarr;

	if (bufcpy == NULL)
	{
		perror("strdup ERROR:");
		return (NULL); }
	token = strtok(bufcpy, " ");
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " "); }
	ptrarr = malloc(sizeof(char *) * (i + 1));
	if (ptrarr == NULL)
	{
		perror("malloc ERROR:");
		free(bufcpy);
		return (NULL); }
	i = 0;
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		ptrarr[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (ptrarr[i] == NULL)
		{
			perror("malloc ERROR:");
			while (i >= 0)
			{
				free(ptrarr[i]);
				--i; }
			free(ptrarr);
			free(bufcpy);
			return (NULL); }
		strcpy(ptrarr[i], token);
		token = strtok(NULL, " ");
		i++; }
	ptrarr[i] = NULL;
	free(bufcpy);
	return (ptrarr);
}
