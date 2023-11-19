#include "main.h"

/**
 * interacrive - interactively executes a command
 * Return: void
*/

void interacrive(void)
{
	char *fullpath, *buffer = NULL;
	char **bufptr = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$: ", 10);
		buffer = tem_getline();
		bufptr = tmp_strtok(buffer);
		if (bufptr[0] != NULL)
		{
			if (strcmp(bufptr[0], "exit") == 0)
			{
				free(bufptr);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(bufptr[0], "env") == 0)
			{
				_getenv();
			}
			fullpath = getpath(bufptr);
			if (fullpath == NULL)
				fullpath = bufptr[0];

			if (execute_file(fullpath, bufptr) == -1)
			{
				perror(getenv("_")); } }
		else
			free(bufptr); }
}
