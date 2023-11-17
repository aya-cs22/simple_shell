#include "main.h"

/**
 * getpath - gets the path of a certain file
 * @filename: name of the file to search for
 * Return: pointer to the path of the file
 * NULL on failure or EOF
*/

char *getpath(char *filename)
{
	char *token;
	char *fullpath, *path = getenv("PATH");
	char *pathcpy = strdup(path);

	token = strtok(pathcpy, ":");
	while (token != NULL)
	{
		fullpath = malloc(sizeof(char) * (strlen(token) + strlen(filename) + 2));
		if (fullpath == NULL)
		{
			perror("malloc ERROR:");
			free(pathcpy);
			return (NULL); }
		strcpy(fullpath, token);
		strcat(fullpath, "/");
		strcat(fullpath, filename);
		if (access(fullpath, X_OK) == 0)
		{
			free(pathcpy);
			return (fullpath); }
		free(fullpath);
		token = strtok(NULL, ":"); }
	free(pathcpy);
	return (NULL);
}
