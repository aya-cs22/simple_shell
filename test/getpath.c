#include "main.h"

/**
 * getpath - gets the path of a file
 * @filename: name of the file
 * Return: path of the file or NULL on failure
*/

char *getpath(char *filename)
{
	char *token;
	char *fullpath, *path = getenv("PATH");
	char *pathcpy = strdup(path);

	if (pathcpy == NULL)
	{
		perror("strdup ERROR:");
		free(filename);
		return (NULL); }
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
