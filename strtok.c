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
		exit(EXIT_FAILURE); }
	token = strtok(bufcpy, "\t\n ");
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " \t\n"); }
	ptrarr = malloc(sizeof(char *) * (i + 1));
	if (ptrarr == NULL)
	{
		perror("malloc ERROR:");
		free(bufcpy);
		exit(EXIT_FAILURE); }
	i = 0;
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		ptrarr[i] = (token);
		token = strtok(NULL, " \t\n");
		i++; }
	ptrarr[i] = NULL;
	free(bufcpy);
	return (ptrarr);
}
