#include "main.h"

/**
 * noninteractive - non-interactively executes a command
 * Return: void
*/

void noninteractive(void)
{
	char *fullpath, *buffer = NULL;
	char **bufptr = NULL;

	while (1)
	{
		buffer = tem_getline();
		if (buffer[0] == '\0' || buffer[0] == '\n')
			continue;
		bufptr = tmp_strtok(buffer);
		if (strcmp(bufptr[0], "exit") == 0)
		{
			
			free(buffer);
			free(bufptr);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(bufptr[0], "env") == 0)
		{
			_getenv();
		}
		fullpath = getpath(bufptr[0]);
		if (fullpath == NULL)
			fullpath = bufptr[0];

		if (execute_file(fullpath, bufptr) == -1)
		{
			perror("ERROR:");
			exit(EXIT_FAILURE); } }
	free(buffer);
	free(bufptr);
}
