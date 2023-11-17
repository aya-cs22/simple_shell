#include "main.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, -1 on failure
 */

int main(int argc, const char *argv[])
{
	char *buffer = NULL;
	char **bufptr = NULL, *fullpath = NULL;
	int status = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$: ", 10);
		buffer = tem_getline();
		if (buffer == NULL)
		{
			free(buffer);
			return (status);
		}
		bufptr = tmp_strtok(buffer);
		if (!bufptr)
			continue;
		
		fullpath = getpath(bufptr[0]);
			if (fullpath == NULL)
			fullpath = bufptr[0];
		bufptr[0] = fullpath;
		if (execute_file(bufptr) == -1)
			{
				perror(getenv("_")); }
		freeme(bufptr);
		free(bufptr);
		if (fullpath != bufptr[0]) 
			free(fullpath);
	}
	return (status);
}
