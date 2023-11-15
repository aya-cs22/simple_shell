#include "main.h"

/**
 * interacrive - interactively executes a command
 * Return: void
*/

void interacrive(void)
{
	char *fullpath, *buffer = NULL;
	char **bufptr = NULL;
	int i = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$: ", 10);
		buffer = tem_getline();
		bufptr = tmp_strtok(buffer);
		if (bufptr[0] != NULL)
		{
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
		else
        	{
			free(bufptr[i]);
			free(bufptr);
    		}
	}
}
