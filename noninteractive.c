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
		int exit_status;
		buffer = tem_getline();
		if (buffer[0] == '\0' || buffer[0] == '\n')
			continue;
		bufptr = tmp_strtok(buffer);
		if (strcmp(bufptr[0], "exit") == 0)
    	{
			exit_status = (bufptr[1] != NULL) ? atoi(bufptr[1]) : 2;

    		free(buffer);
    		free(bufptr);
    		exit(exit_status); }

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
