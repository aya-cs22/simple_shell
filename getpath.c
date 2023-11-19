#include "main.h"

/**
 * getpath - gets the path of a certain file
 * @filename: name of the file to search for
 * Return: pointer to the path of the file
 * NULL on failure or EOF
*/

char *getpath(char **filename)
{
	char *token;
	int i = 0;
	char *fullpath, *path = getenv("PATH");
	char *pathcpy = strdup(path);

	if (pathcpy == NULL)
	{
		perror("strdup ERROR:");
		path = NULL;
		exit(EXIT_FAILURE); }
	token = strtok(pathcpy, ":");
	while (token != NULL)
	{
		fullpath = malloc(sizeof(char) * (strlen(token) + strlen(filename[0]) + 2));
		if (fullpath == NULL)
		{
			perror("malloc ERROR:");
			free(pathcpy);
			for (i = 0; filename[i]; i++)
			{
				free(filename[i]); }
			free(filename);
			exit(EXIT_FAILURE); }
		strcpy(fullpath, token);
		strcat(fullpath, "/");
		strcat(fullpath, (const char *)filename[0]);
		if (access(fullpath, X_OK) == 0)
		{
			free(pathcpy);
			return (fullpath); }
		free(fullpath);
		token = strtok(NULL, ":"); }
	return (NULL);
}
